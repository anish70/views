
#include <iostream>
 
using namespace std;

int flip(int bit)
{
	return 1 ^ bit;
}

int sign(int a)
{
	return (flip(a >> 31) & 1);
}

int getMax(int a, int b)
{
	int c = sign(a -b);	// -1 or not
	int q = flip(c);	// flip
	return a*c + b*q;
}

int main(int argc, char **argv)
{
	int first, second;
	cout << "Enter the first number: ";
	cin  >> first;

	cout << "Enter the second number: ";
	cin  >> second;

	cout << "Max is: " << getMax(first, second) << endl;
	return 0;
}


