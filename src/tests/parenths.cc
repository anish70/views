#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <list>

using namespace std;

void addParen(list<string> myL, char str[], int left, int right, int count)
{
	if (left < 0 || right < left) return;

	if (left == 0 && right == 0) {
		cout << str << endl;
	} else {
		if (left > 0) {
			str[count] = '(';
			addParen(myL, str, left -1, right, count +1);
		}

		if (right > left) {
			str[count] = ')';
			addParen(myL, str, left, right -1, count +1);
		}
	}
}

void generateParenths(int count)
{
	char str[(count*2) +1];
	str[(count*2)] = '\0';
	list<string> myL;
	addParen(myL, str, count, count, 0);

	list<string>::iterator it;
	for (it = myL.begin(); it != myL.end(); it++)
		cout << (*it).data() << endl;
}


int
main()
{
	generateParenths(12);
}
