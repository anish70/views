#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int
GCD(int M, int N) 
{ 
	// Pre : M and N are defined and >= 0 
	// Post: Returns the greatest common divisor of M and N.
	int Result;

	if ((N <= M) && (M % N == 0)) { 
		Result = N;                  // stopping case 
	} else if (M < N) { 
		Result = GCD(N, M);          // recursion 
	} else { 
		Result = GCD(N, M % N);    // recursion 
	} 

	return Result; 
}


int64_t factorial(int num)
{
	return num == 1 ? num : num * factorial(num -1);
}


int
main(int argc, char *argv[])
{
	int num1 = atoi(argv[1]);
	int num2 =  argv[2] ?  atoi(argv[2]) : 0;

	printf("Factorial of %d is %lld\n", num1, factorial(num1));
	printf("GCD of %d and %d is  %d\n", num1, num2, GCD(num1, num2));

	return 0;
}
