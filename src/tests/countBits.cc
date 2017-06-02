#include <algorithm>
#include <iostream>
 
using namespace std;
 
int countBits(int x)
{
	int count = 0;

	while (x > 0) {           // until all bits are zero
		if ((x & 1) == 1)     // check lower bit
		   count++;
		x >>= 1;              // shift bits, removing lower bit
	}
	return count;

}

unsigned int f(unsigned int x)
{
    switch (x) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        default:
            return f(x/4) + f(x%4);
    }
}

int turnOffK(int n, int k)
{
    // k must be greater than 0
    if (k <= 0) return n;
 
    // Do & of n with a number with all set bits except
    // the k'th bit
    return (n & ~(1 << (k - 1)));
}


unsigned int reverse(unsigned int x)
{
	unsigned int ret = x ^ 0xffffffff;
	return ret;
}

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

char *StrDup(const char *s)
{
    static char *d = (char *)malloc (strlen (s) + 1);
    if (d == NULL) return NULL;         
    strncpy (d,s, strlen(s));          
    return d;                         
}

char *StrDup2(const char *s)
{
    static char *d = (char *)malloc (strlen (s) + 1);
    if (d == NULL) return NULL;         
    for (int i = 0; i < strlen(s); i++)
	    d[i] = s[i];
    return d;                         
}

int
main(int argc, char *argv[])
{
	int input;

	cout << "enter an input integer: ";
	cin >> input;

	cout << "Input Bits: " << bitset<16>(input) << endl;

	cout << "Bit Count: " << f(input) << endl;
	cout << "Check 3rd bit set: " << CHECK_BIT(input, 3) << endl;
	cout << "Turn Off 3rd bit: " << bitset<16>(turnOffK(input, 3)) << endl;
	cout << "Reverse Bits: " << bitset<16>(reverse(input)) << endl;

	string value;

	cout << "Enter a String: ";
	cin >> value;
	cout << "strdup value: " << StrDup2(value.c_str()) << endl;
}


