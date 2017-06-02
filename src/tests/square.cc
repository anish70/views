#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <map>

using namespace std;

int multiply(int a, int b) {
	if (b == 1) {
		return a;
	}

	int res= multiply(a, b / 2) << 1;
	return b % 2 == 0 ? res : res + a;
}

int square(int a) {
	return multiply(a, a);
}

int
main()
{
	int a = -10;
	if (a < 0) {
		a = -a;
	}
	printf("%d\n", square(a));
}

