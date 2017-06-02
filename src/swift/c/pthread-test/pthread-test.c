#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

void *child(void *dummy) {
    for (int i=4; i<=6; i++) {
        printf("C %2d\n",i);
    }

    pthread_exit(NULL);
    return NULL;
}

int main(int argc, const char * argv[]) {

    for (int i=1; i<=3; i++) {
        printf("P %2d\n", i);
    }

   pthread_t thrs[3];

    for (int i=0; i<=2; i++)
	(void) pthread_create(&thrs[i], NULL, child, NULL);

    for (int i=7; i<=9; i++) {
        printf("P %2d\n", i);
    }

    pthread_exit(NULL);
    
    return 0;
}
