#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <map>
 
using namespace std;
 
int countFactorZeros(int num)
{
	int count = 0;

	if (num < 0) return -1;

	for (int i = 5; num/i > 0; i+= 5) {
		count += num/i;
	}
	return count;
}

#define MIN(a,b) (a<b)?a:b

int findMin(int a[], int b[])
{
	int diff;
	int min = 2^31;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			diff=abs(a[i]-b[j]);
			if (diff < min) {
				min = diff;
			}
		}
	}
	return min;
}

int getMaxSum(int a[]) {
	int sum=0;
	int maxS = 0;

	for (int i = 0; i < 5; i++) {
		sum += a[i];
		if (sum < maxS) maxS = sum;
		else sum = 0;
	}

	return maxS;
}

int mySum(int a, int b)
{
	while (b != 0) {
		int sum = a^b;
		int carry = (a&b) << 1;
		a = sum;
		b = carry;
	}
	return a;	
}

void getSumMatch(int a[], int b[], int sum)
{
	map<int,int> M;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if ((a[i] + b[j]) == sum) {
				M.insert(pair<int,int>(i,j));
			}
		}
	}

	for (map<int,int>::iterator it = M.begin(); it != M.end(); it++) {
		cout << "\tfirst= " << it->first << " Sec = " << it->second << endl;
	}
}


int
main(int argc, char **argv)
{
	cout << "FactorZeros of 10=" << countFactorZeros(10) << endl;
	cout << "FactorZeros of 20=" << countFactorZeros(20) << endl;

	int a[5] = {1,3,15,11,2};
	int b[5] = {23,137,5,19,8};
	cout << "Min =" << findMin(a,b) << endl;
	cout << "sum =" << mySum(89898,77667) << endl;

	getSumMatch(a,b, 20);

	int c[5] = {5,-9,6,-2,3};
	cout << "Max =" << getMaxSum(a) << endl;

}
