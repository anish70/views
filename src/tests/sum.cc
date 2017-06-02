
#include <iostream>
 
using namespace std;

int sum(int a, int b)
{
	while (b != 0) {
		int c = a^b;
		int carry = (a&b) << 1;
		a = c;
		b = carry;
	}

	return a;
}

int main(int argc, char **argv)
{
	int first, second;
	cout << "Enter the first number: ";
	cin  >> first;

	cout << "Enter the second number: ";
	cin  >> second;

	cout << "Sum is: " << sum(first, second) << endl;
	return 0;
}


