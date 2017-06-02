#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

void remove_spaces2(char *str)
{
	vector<char> inOrder;

	for(int i = 0; i < strlen(str); i++) {
		if (!isblank(str[i])) 
			inOrder.push_back(str[i]);
	}

	str = reinterpret_cast<char*> (&inOrder[0]);
	cout << str << endl;
}

void remove_spaces(char* str)
{
        int i = 0, j = 0;

       for(i = 0; i < strlen(str); i++) {
            if (str[i] != ' ') {
		  str[j] = str[i];
		  j++;
           }
        }

        str[j] = '\0';
	printf("i = %d, j = %d, New string = %s\n", i, j, str);
}

int
main()
{
	char s[] = "    The      white fox jump  ed";

	remove_spaces2(s);
}

