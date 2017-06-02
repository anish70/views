#include <stdio.h>
#include <iostream>

using namespace std;

#define L(a) (sizeof((a)) / sizeof((a)[0]))

void show(unsigned long l) {
    printf("%lu\n", l);
}

void test0() {
    int c[5];
    typedef struct _st { int n; char c; } st;
    st sts[10];

    //show(L(1));
    show(L("three"));
    show(L(c));
    show(L(sts));
    cout << "\tdone with test0\n";
}

void test1(unsigned long c) {
    int v[c][2*c];
    show(L(v));
}

int main()
{
	test0();
	test1(4);
}
