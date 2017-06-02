#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;
 

int getMaxMinutes(int input[], int results[], int index, int Count)
{
	if (index > Count) {
		return 0;
	}

	if (results[index] == 0) {
		int bestWith = input[0] + getMaxMinutes(input, results, index +2, Count);
		int bestWithOut = getMaxMinutes(input, results, index +1, Count);
		results[index] = std::max(bestWith, bestWithOut);
	}

	return results[index];
}

int main ()
{
	int input[8] = { 30, 15, 60, 75, 45, 15, 15, 45}; 
	int *results = new int[9];

	getMaxMinutes(input, results, 0, 8);
 
	return 0;
}
