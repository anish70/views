#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
 
 
/* Driver program to test to print printDups*/
int main()
{
	string str1, str2;
	cout << "String1 enter?";
	cin >> str1;
	cout << "String2 enter?";
	cin >> str2;

	// Sort both strings
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	cout << "The two strings are " << (str1 == str2? " " : "*NOT* ")  << "anagram of each other\n";
}
