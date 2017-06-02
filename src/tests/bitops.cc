#include <iostream>

using namespace std;

int
repeatedArithmeticShit(int x, int count) {
	for (int i = 0; i < count; i++) {
		x >>= 1; // arithmetic shift by a bit
	}
	return x;
}

int
repeatedLogiclShit(unsigned int x, int count) {
	for (int i = 0; i < count; i++) {
		x >>= 1; // arithmetic shift by a bit
	}
	return x;
}

int clearBitX(int num, int x) {
	num &= ~(1 << x);
	return num;
}

int setBitX(int num, int x) {
	num |= (1 << x);
	return num;
}

int toggleBitX(int num, int x) {
	num ^= (1 << x);
	return num;
}

bool isBitXSet(int num, int x) {
	bool bit = (num >> x) & 1;
	return bit;
}

int ToggleNthBit (int num, unsigned char n)
{
    int bitpos = 1 << n;

    if (num & bitpos) // is it set?
        num &= ~bitpos;
    else
        num |= bitpos;

    return num;
}

int
main(void)
{
	// int x = repeatedArithmeticShit(-93242, 40);
	// int y = repeatedLogiclShit(-93242, 40);
	// std::cout << "x = " << x << "y = " << y << std::endl;

	int x = 248;
	cout <<  "Input Bits:\t" << bitset<12>(x) << endl;
	x = setBitX(x, 11);
	cout <<  "Set bit 11:\t" << bitset<12>(x) << " BitXSet: " << isBitXSet(x, 11) <<  endl;
	x = clearBitX(x, 11);
	cout <<  "Clear bit 11:\t" << bitset<12>(x) << " BitXSet: " << isBitXSet(x, 11) <<  endl;
	x = ToggleNthBit(x, 10);
	cout <<  "Flip bit 10:\t" << bitset<12>(x) << endl;
	x = ToggleNthBit(x, 10);
	cout <<  "Flip bit 10:\t" << bitset<12>(x) << endl;
	x = ToggleNthBit(x, 10);
	cout <<  "Flip bit 10:\t" << bitset<12>(x) << endl;
	x = ToggleNthBit(x, 10);
	cout <<  "Flip bit 10:\t" << bitset<12>(x) << endl;
}

