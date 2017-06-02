#include <stdio.h>
#include <stdlib.h>

/*
 * NOTE:  This problem is not yet ready to be run.
 * See Orion for details if you want to use it.
 */

/**************************************************************
                        HOW BIG IS IT?
 What do each of the invocations of show() print, and why?
 If there will be a compilation error (and there are a few),
 explain why.
**************************************************************/


#define L(a) (sizeof(a) / sizeof(a[0]))

void show(unsigned long l) {
    printf("%lu\n", l);
}

void test0() {
    int b[];
    int c[5];
    typedef struct _st { int n; char c; } st;
    st sts[10];

    show(L(1));
    show(L("three"));
    show(L(b));
    show(L(c));
    show(L(sts));
}

void test1(unsigned long c) {
    int v[c][2*c];
    show(L(v));
}

// Does this differ from test1?  If so, why? 
void test2(unsigned long c) {
    int *d = malloc(c * sizeof(int));
    show(L(d));
    show(L(*d));
    free(d);
}

// Without changing the malloc(), can you declare d in such 
// a way that L(*d) is actually 100?  (You will have to change 
// its type.)  And once you've done that, what will L(d) be?
void test3() {
    int *d;
    d = malloc(100 * sizeof(int));
    show(L(d));
    show(L(*d));
    free(d);
}

int (*f())[10] {
    static int buf[10];
    printf("Betelgeuse\n");
    return &buf;
}

void dont_look_at_this() {
    show( L(f()) );
    show( L(*f()) );
}

void dont_look_at_this_either() {
    int c = 5;
   int v[c][2*c];

    show(c);
    show(sizeof ++c);
    show(c);
    show(sizeof v[++c]);
    show(c);
}

int main(int argv, char **argc) {
    test0();
    printf("--\n");

    test1(20);
    printf("--\n");

    test2(20);
    printf("--\n");

    test3();
    printf("--\n");

    dont_look_at_this();
    printf("--\n");

    dont_look_at_this_either();
    printf("--\n");

    return 0;
}
