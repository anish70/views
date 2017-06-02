#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;


void
bubble_sort(int input[], int nelem)
{
        int swapped = 1;
	int temp;

        int X[nelem];
        for (int i = 0; i < nelem && swapped == 1; i++) {
		X[i] = input[i];
	}

        for (int i = 0; i < nelem && swapped == 1; i++) {
                swapped = 0;

                for (int j = 0; j < nelem-(i+1) ; j++) {
                        if (X[j]>X[j+1]) {
                                temp = X[j];
                                X[j] = X[j+1];
                                X[j+1] = temp;
                                swapped = 1;
                        }
                }
        }


        for (int i = 0; i < nelem; i++) {
		cout << " " << X[i];
	}
	cout << endl;
}


int
main()
{
	int input[] = {12, 2, 50, 6, 9, 33, 40, 77, 1, 99, 101, -2, 0};
	int nelem = sizeof(input)/sizeof(input[0]);

	bubble_sort(input, nelem);

	return 0;
}
