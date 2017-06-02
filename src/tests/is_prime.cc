#include <math.h>
#include <stdio.h>
#include <iostream>
 
using namespace std;
 
bool isPrime(unsigned int x)
{
	if (x < 2) return false;
	if (x == 2) return true;

	for (int i = 2; i <= sqrt(x); i++) {
		if ((x%i) == 0)
			return false;
	}

	return true;
}

int
main(int argc, char *argv[])
{
	for (int j = 0; j < INT_MAX; j++) {
		if (isPrime(j)) {
			printf("%d\n", j);
		}
	}	
}


