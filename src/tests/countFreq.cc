#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <map>

using namespace std;

void
countFrequencies(int input[], size_t num)
{
	map<int, int> frequencies;
	map<int,int>::iterator it;


	for(int i = 0; i < num; i++) {
		it = frequencies.find(input[i]);
		if (it != frequencies.end()) {
			++it->second;
		} else{
			frequencies.insert(std::pair<int,int>(input[i], 1));
		}
	}

	cout << "Frequency map contains:\n";
	for (it=frequencies.begin(); it!=frequencies.end(); ++it)
	    std::cout << "Frequencey of " << it->first << " : " << it->second << '\n';

}

int
main()
{
	int first[] = {9,9,9,9,9,10,12,12,12,12,10,10,10,10,9,9,9, 10, 11, 12};
	size_t num=sizeof(first)/sizeof(first[0]);
	countFrequencies(first, num);
}
