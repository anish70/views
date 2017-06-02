#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

bool isUnique (char *str)
{
	int j = 0;
	bool *ch = new bool[256];

	for (int i=0; i < strlen(str); i++)  {
		int val = str[i];
		if (ch[val] == true)  {
			delete ch;
			return false;
		}
		ch[val] = true;
	} 

	delete ch;
	return true;
}


void dedupe(char *str)
{ 
	int j = 0;
	bool *ch = new bool[256];

	for (int i=0; i < strlen(str); i++)  {
		int val = str[i];
		if (ch[val] == false)  {
			str[j++] = val;
			ch[val] = true;
		} 
	} 

	str[j] = '\0';
	delete ch;
}

int main()
{
	char deDup[128];
	snprintf(deDup, 128, "00a000a0gaaackkkccbbbddeeaaaffghhhhijjjkkl```l");
	printf("Before: %s(%ld)\n", deDup, strlen(deDup));
	printf("Before: isUnique: %d\n", isUnique(deDup));
	dedupe(deDup);
	printf("After: %s\n", deDup);
	printf("After: isUnique: %s: is %d\n", deDup, isUnique(deDup));
}
