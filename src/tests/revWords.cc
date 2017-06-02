#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


// reverse any string passed to this method
void
reverseString(char* str, int len)
{
	char temp = 0;
	int i = 0;
	int j = len -1;

	// swap chars from front with chars from back
	for (i = 0; i < j; i++, j--) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

void reverseWords(char * str)
{
	int i = 0, j = 0;

	// reverse the given string
	reverseString(str, strlen(str));

	// reverse each substr
	while (true) {
          if (*(str+j) == ' ' || *(str+j) == '\0') {
              reverseString(str+i, j-i);
              i = j+1;
          }

	  // eol
          if (*(str+j) == '\0') {
              break;
          }
          j++;
    }
}

int
main(int argc, char **argv)
{
	char s[] = "This is my name Anish. I work at Netapp.";
	printf("Before = %s\n", s);

	reverseWords(s);
	printf("Now = %s\n", s);
}
