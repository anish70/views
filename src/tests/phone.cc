#include <stdio.h>
#include <string.h>

// hashTable[i] stores all characters that correspond to digit i in phone
const char hashTable[10][5] = {
		"",		// 0
		"",		// 1
		"abc",		// 2
		"def",		// 3
		"ghi",		// 4
		"jkl",		// 5
		"mno",		// 6
		"pqrs",		// 7
		"tuv",		// 8
		"wxyz"		// 9
};

// A recursive function to print all possible words that can be obtained by
// input number[] of size n.  The output words are one by one stored in output[]
void
printWordsUtil(int number[], char output[], int curr_digit, int n)
{
	// Base case, if current output word is prepared
	if (curr_digit == n) {
		printf("%s\n", output);
		return ;
	}

	// Try all 3 possible characters for current digir in number[]
	// and recur for remaining digits
	for (int i=0; i< strlen(hashTable[number[curr_digit]]); i++) {
		output[curr_digit] = hashTable[number[curr_digit]][i];
		printWordsUtil(number, output, curr_digit+1, n);
		if (number[curr_digit] == 0 || number[curr_digit] == 1) {
			return;
		}
	}
}

int
main(void)
{
	int number[] = {8, 9, 9};
	int n = sizeof(number)/sizeof(number[0]);
	char result[n+1];
	result[n] ='\0';
	printWordsUtil(number, result, 0, n);
	return 0;
}
