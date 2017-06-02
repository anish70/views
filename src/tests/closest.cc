#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <map>
 
using namespace std;
 
void getClosest(int arr[], int num, int sum)
{
	int min = INT_MAX;
	int tot;
	int x, y;	

	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			tot = arr[i] + arr[j];
			if (tot < sum) {
				min = tot;
				if (tot < min) {
					x= i; y = j;
				}
			}
		}
	}

	printf("a[%d] = %d, a[%d] = %d and is %d\n", x, arr[x], y, arr[y], tot);
}


int
main(int argc, char **argv)
{
	int a[] = {0, 22, 28, 29, 30, 40, 53};
	getClosest(a, 6, 54);
}
