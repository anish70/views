#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
 
using namespace std;
 
int
main(int argc, char **argv)
{
	int a =2489;
	int b = 9288;
	cout << "a = " << a << " b = " << b << endl;
	a = a^b;
	b = a^b;
	a = a^b;
	cout << "a = " << a << " b = " << b << endl;
}
