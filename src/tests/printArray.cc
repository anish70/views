#include <iostream>

using namespace std;

const int size = 5;

int main()
{
	int arr[size][size]= {
			{1 ,2, 3, 4,6},
			{5, 4, 3, 5,7},
			{6, 5, 9, 8,9},
			{9, 8, 7, 6,1},
			{1, 8, 3, 6,2}
			};

	for (int i = 0 ; i < size; i++) {
		int temp = i;
		for (int j=0; j <= i; j++ )
			cout << arr[j][temp--];
		cout << endl;
	}

	for (int i = 1 ; i < size; i++) {
		int temp = i;
		for (int j = size -1; j >= i; j--)
			cout << arr[temp++][j];
		cout << endl;
	}
}
