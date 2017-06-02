#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class BitSet {
public:
	int *bitset;

	BitSet(int size) {
		this->bitset = new int[(size >>5) +1];
	}

	bool get(int pos) {
		int wN = (pos >> 5);	// divide by 32
		int bN = (pos & 0x1F);	// mod 32
		return (bitset[wN] & (1 << bN)) != 0;
	}

	void set(int pos) {
		int wN = (pos >> 5);	// divide by 32
		int bN = (pos & 0x1F);	// mod 32
		bitset[wN] |= (1 << bN);
	}
};

void checkDups(int total)
{
	int input[total];

	for (int i = 0; i < total; i++) {
		input[i] = i;
	}

	for (int i = 0; i < 32; i++) {
		input[i] = i + 1000;
	}

	BitSet *bs = new BitSet(total);
	for (int i = 0; i < total; i++) {
		int num = input[i];
		int num0 = num -1;
		if (bs->get(num0)) {
			cout << " " << num;
		} else {
			bs->set(num0);
		}
	}
}

int main()
{
	int total;

	cout << "Input how many elements:? ";
	cin >> total;

	checkDups(total);
	return 0;
}
