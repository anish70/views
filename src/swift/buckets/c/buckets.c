#include <err.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_SIZE  512
#define RESULT_SIZE 11

void bucketize(long *input, long input_size, long *buckets) {
    long *array = calloc(input_size, sizeof(*input));

    for (int i=0; i<11; i++) {
        buckets[i] = 0;
    }

    int array_size = 0;
    for (int i=0, j=0; i<input_size; i++) {
        if (input[i] < 100) {
            array[j++] = input[i];
            array_size++;
        }
    }

    for (int bnum=0; bnum<11; bnum++) {
        for (int i=0; i<array_size; i++) {
            long group;
            char buf[256];

            sprintf(buf, "%ld", array[i]);
            group = strtol(buf+strlen(buf)-1, NULL, 10);
            if (group == bnum) {
                buckets[group] += array[i];
            }
        }
    }

    array_size = 0;
    for (int i=0, j=0; i<input_size; i++) {
        if (input[i] >= 100) {
            array[j++] = input[i];
            array_size++;
        }
    }

    for (int i=0; i<array_size; i++) {
        buckets[10] += array[i]; 
    }

    free(array);
}

void show_mismatch(long *expected, long *actual) {
    fprintf(stderr, "expected: [");
    for (int i=0; i<RESULT_SIZE; i++) {
        fprintf(stderr, "%5ld", expected[i]);
    }
    fprintf(stderr, "]\n");

    fprintf(stderr, "actual:   [");
    for (int i=0; i<RESULT_SIZE; i++) {
        fprintf(stderr, "%5ld", actual[i]);
    }
    fprintf(stderr, "]\n");
}

void _read_and_test(const char *fn, FILE *fp, long *expected_result) {
    long numbers[MAX_INPUT_SIZE];
    int current = 0;
    int error = 0;
    char buf[128];
    char *end;

    while (fgets(buf, sizeof(buf), fp)) {
        buf[strcspn(buf, "\n")] = 0;

        long num = strtol(buf, &end, 10);
        if (end == buf || !(isspace(*end) || *end == '\0') || errno == ERANGE) {
            fprintf(stderr, "[%s] input error: buf: [%s] *end: [%d]: errno: %d\n", fn, buf, *end, errno); 
            error = 1;
        } else if (current == MAX_INPUT_SIZE) {
            fprintf(stderr, "[%s] input error: TOO MANY NUMBERS!\n", fn); 
            exit(1);
        } else {
            numbers[current++] = num;
        }

        if (error)
            exit(1);
    }

    long buckets[RESULT_SIZE];
    bucketize(numbers, current, buckets);
    
    for (int i=0; i<RESULT_SIZE; i++) {
        if (buckets[i] != expected_result[i]) {
            error++;
        }
    }

    if (error) {
        fprintf(stderr, "test FAILED: %s\n", fn);
        show_mismatch(expected_result, buckets);
    } else {
        fprintf(stderr, "test passed: %s\n", fn);
    }
}

void read_and_test(const char *fn, long *expected_result) {
    FILE *fp = fopen(fn, "r");
    if (fp == NULL) {
        err(1, "%s", fn);
    }

    _read_and_test(fn, fp, expected_result);
    fclose(fp);
}


int main(void) {
    long expected1[] = {450, 460, 470, 480, 490, 500, 510, 520, 530, 540, 6225};
    read_and_test("./input1.dat", expected1);

    long expected2[] = {910, 839, 1120, 1014, 1126, 900, 974, 866, 1698, 1384, 10944};
    read_and_test("./input2.dat", expected2);

    long expected3[] = {0, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    read_and_test("./input3.dat", expected3);
}

