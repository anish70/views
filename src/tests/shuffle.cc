#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

void printMe(int cards[]);

void printMe(int cards[], int howmany) {
	for (int i = 0; i < howmany; i++) {
		cout << " " << cards[i];
	}
	cout << endl;
}

int MyRandom(int lower, int higher, int howmany) {
	int ret = abs(lower + (int) (rand() * (higher -lower + 1)));
	return (ret % howmany);
}

void Shuffle(int cards[], int howmany, int m) {	// Subset Shuffle
	int subSet[m];

	for (int i = 0; i < m; i++)
		subSet[i] = cards[i];

	for (int i = 0; i < m; i++) {
		int k = MyRandom(0, i, m);
		if (k < m) {
			subSet[k] = cards[i];
		}
	}

	printMe(subSet, m);

}

void Shuffle(int cards[], int howmany) {
	for (int i = 0; i < howmany; i++) {
		int k = MyRandom(0, i, howmany);
		int temp = cards[k];
		cards[k] = cards[i];
		cards[i] = temp;
	}

	printMe(cards, howmany);
}

int main ()
{
	srand (time(NULL)); /* initialize random seed: */

	int howmany = 52;
	int cards[howmany];

	for (int i = 0; i < howmany; i++) cards[i] = i;
	Shuffle(cards, howmany);

	for (int i = 0; i < howmany; i++) cards[i] = i;
	Shuffle(cards, howmany, 32);
}
