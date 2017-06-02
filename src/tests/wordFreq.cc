#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <map>
#include <locale>

using namespace std;

void
getFrequencies(string input[], size_t num)
{
	map<string, int> frequencies;
	map<string,int>::iterator it;
	locale loc;

	for(int i = 0; i < num; i++) {
		it = frequencies.find(input[i]);
		if (it != frequencies.end()) {
			++it->second;
		} else{
			frequencies.insert(pair<string,int>(input[i], 1));
		}
	}

	cout << "Word Frequency map contains:\n";
	for (it=frequencies.begin(); it!=frequencies.end(); ++it)
	    cout << "Frequencey of " << it->first << " : " << it->second << '\n';

}

int
main()
{
	int num = 6;
	string first[6] = {"month", "month", "egg", "egg", "first", "water" };
	getFrequencies(first, num);
}
