#include <errno.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <libkern/OSAtomic.h>

typedef struct hte_s hte_t;

struct hte_s {
    hte_t    *next;
    uint32_t  key;
    uint64_t  hits;
};

typedef struct bucket_s bucket_t;

struct bucket_s {
    pthread_mutex_t  mutex;
    hte_t           *head;
};

typedef struct ht_s ht_t;

struct ht_s {
    uint32_t  num_buckets;
    bucket_t *buckets;
};

ht_t *ht_old; // before migration
ht_t *ht_new; // after migration

uint32_t num_entries;

#define BUCKET_INDEX(key, ht) (key % (ht)->num_buckets)

ht_t *provision_ht(uint32_t num_buckets) {
    uint32_t  bucket_index;
    ht_t     *ht_to_return;
    int       status;

    ht_to_return = malloc(sizeof(ht_t));

    if (NULL == ht_to_return) exit(-ENOMEM);

    ht_to_return->num_buckets = num_buckets;

    ht_to_return->buckets = malloc(num_buckets * sizeof(bucket_t));

    if (NULL == ht_to_return->buckets) exit(-ENOMEM);

    for (bucket_index = 0; bucket_index < num_buckets; bucket_index++) {
        status = pthread_mutex_init(&ht_to_return->buckets[bucket_index].mutex, NULL);
        if (0 != status) exit(-status);
        ht_to_return->buckets[bucket_index].head = (hte_t *)NULL;
    }

    return ht_to_return;
}

void populate_ht_old(void) {
    hte_t    *hte;
    uint32_t  hte_key;
    uint32_t  old_bucket_index;
    bucket_t *old_bucket_ptr;

    for (hte_key = 1; hte_key <= num_entries; hte_key++) {
        hte = malloc(sizeof(hte_t));
        if (NULL == hte) exit(-ENOMEM);
        hte->key  = hte_key;
        hte->hits = 0;

        old_bucket_index = BUCKET_INDEX(hte_key, ht_old);
        old_bucket_ptr   = &ht_old->buckets[old_bucket_index];

        hte->next            = old_bucket_ptr->head;
        old_bucket_ptr->head = hte;
    }
}

void *load_generator(void *dummy) {
    hte_t    *hte_in_ht_new;
    hte_t    *hte_in_ht_old;
    hte_t    *hte_with_matching_key;
    uint32_t  key;
    bucket_t *new_bucket_ptr;
    bucket_t *old_bucket_ptr;
    int       status;

    // loop forever... parent pthread exiting will kill us

    while (1) {
        key = (rand() % num_entries) + 1; // keys in 1..num_entries range

        // search identified ht_old bucket for matching key

        old_bucket_ptr = &ht_old->buckets[BUCKET_INDEX(key, ht_old)];

        status = pthread_mutex_lock(&old_bucket_ptr->mutex);
        if (0 != status) exit(-status);

        hte_in_ht_old = old_bucket_ptr->head;

        while (1) {
            if ((NULL == hte_in_ht_old) || (key == hte_in_ht_old->key)) break;

            hte_in_ht_old = hte_in_ht_old->next;
        }

        if (NULL == hte_in_ht_old) {
            // didn't fine hte in ht_old... check ht_new (already provisioned before migrate_ht_old_to_ht_new() is called)

            new_bucket_ptr = &ht_new->buckets[BUCKET_INDEX(key, ht_new)];

            status = pthread_mutex_lock(&new_bucket_ptr->mutex);
            if (0 != status) exit(-status);

            hte_in_ht_new = new_bucket_ptr->head;

            while (1) {
                if (NULL == hte_in_ht_new) exit(-ERANGE);

                if (key == hte_in_ht_new->key) break;

                hte_in_ht_new = hte_in_ht_new->next;
            }

            status = pthread_mutex_unlock(&new_bucket_ptr->mutex);
            if (0 != status) exit(-status);

            hte_with_matching_key = hte_in_ht_new;
        } else {
            // hte was found in ht_old... so make sure it isn't also in ht_new (here, however, ht_new might not yet be provisioned)

            hte_with_matching_key = hte_in_ht_old;

            if (NULL != ht_new) {
                new_bucket_ptr = &ht_new->buckets[BUCKET_INDEX(key, ht_new)];

                status = pthread_mutex_lock(&new_bucket_ptr->mutex);
                if (0 != status) exit(-status);

                hte_in_ht_new = new_bucket_ptr->head;

                while (NULL != hte_in_ht_new) {
                    if (key == hte_in_ht_new->key) exit(-ERANGE);

                    hte_in_ht_new = hte_in_ht_new->next;
                }

                status = pthread_mutex_unlock(&new_bucket_ptr->mutex);
                if (0 != status) exit(-status);
            }
        }

        status = pthread_mutex_unlock(&old_bucket_ptr->mutex);
        if (0 != status) exit(-status);

        OSAtomicAdd32(1, (int32_t *)&hte_with_matching_key->hits);

    }
}

void migrate_ht_old_to_ht_new(void) {
    printf("Not yet implemented.\n");
}

int main(int argc, const char * argv[]) {
    pthread_t *child_pthread;
    uint32_t  num_buckets;
    int       status;
	int		  num_load_gen;


    // fetch user's (initial) hash table parameters
    printf("How many hash table entries? ");
    scanf("%u", &num_entries);
    printf("How many hash table buckets (initially)? ");
    scanf("%u", &num_buckets);
    printf("How many load generators? ");
    scanf("%u", &num_load_gen);

	if (num_load_gen <= 0 || num_load_gen > num_entries) {
		printf("Invalid num_load_gen: %d\n", num_load_gen);
		exit(-1);
	}

    // provision initial hash table
    ht_old = provision_ht(num_buckets);

    // indicate that new hash table is not yet provisioned
    ht_new = NULL;

    // populate initial hash table with num_entries hte_t's
    populate_ht_old();

    // kick off load generator
	child_pthread = malloc(sizeof(pthread_t) * num_load_gen);

	for (int i =0; i< num_load_gen; i++) {
			status = pthread_create(&child_pthread[i], NULL, load_generator, NULL);
			if (0 != status) exit(-status);
	}


    // fetch user's updated hash table parameter (num_buckets)
    printf("How many hash table buckets (updated)? ");
    scanf("%u", &num_buckets);

    // provision new hash table
    ht_new = provision_ht(num_buckets);

    // perform a safe migration of all hte's from ht_old to ht_new
    migrate_ht_old_to_ht_new();

    // fetch "ok" to terminate the test
    printf("Hit RETURN key to stop. ");
    (void)getchar();
    (void)getchar();
    printf("OK - we are done.\n");

    return 0;
}
