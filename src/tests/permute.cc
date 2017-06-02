#include <stdio.h>
#include <string.h>
 
/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string.
*/
void
permute(char *a, int index, int len)
{
	int i;

	if (index == len) {
		printf("%s\n", a);
	} else {
		for (i = index; i <= len; i++) {
			swap((a+index), (a+i));
			permute(a, index+1, len);
			swap((a+index), (a+i)); //backtrack
		}
	}
}
 
/* Driver program to test above functions */
int main()
{
	char str[] = "DEFG";
	permute(str, 0, strlen(str)-1);
}

