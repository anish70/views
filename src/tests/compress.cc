#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;


/* Algorithm:
 * 1. Get a bool array for 256 character[]
 * 2. Count how many times a character shows up, and also mark which char.
 * 3. print count
 */

char *compress(char *str)
{
        int j = 0;
        bool *ch = new bool[256];
        int *count = new int[256];

        for (int i=0; i < strlen(str); i++)  {
                int val = str[i];
                if (ch[val] == false)  {
                        str[j++] = val;
                        ch[val] = true;
                } 
                count[val]++;
        }

        str[j] = '\0';

	cout << "str = " << str << endl;

        static char *out = new char[256];
        j = 0;
        for (int i = 0; i < strlen(str); i++) {
		int val = str[i];
                out[j++] = val;
                out[j++] = 0x30 + count[val];
        }
        out[j] = '\0';

	cout << "out = " << out << endl;

	delete [] ch;
	delete [] count;

        return out;
}

char *compress2(char *str)
{
	vector<char> inOrder;
	map<char, int> frequencies;
	map<char,int>::iterator it;

	for(int i = 0; i < strlen(str); i++) {
		it = frequencies.find(str[i]);
		if (it != frequencies.end()) {
			++it->second;
		} else{
			// frequencies.insert(pair<char,int>(str[i], 1));
			frequencies[str[i]] = 1;
			inOrder.push_back(str[i]);
		}
	}

	cout << "Compress map contains:\t";
	for (int i = 0; i < inOrder.size(); i++) {
		it = frequencies.find(inOrder[i]);
		cout << inOrder[i] << it->second;
	}
	cout << endl;

	return (reinterpret_cast<char*> (&inOrder[0]));
}


int main()
{
	char deDup[128];
	snprintf(deDup, 128, "00a000a0gaaackkkccbbbddeeaaaffghhhhijjjkkl```l");
	printf("Before: %s(%ld)\n", deDup, strlen(deDup));
	// printf("After: compress: %s\n", compress(deDup));
	// snprintf(deDup, 128, "00a000a0gaaackkkccbbbddeeaaaffghhhhijjjkkl```l");
	// compress2(deDup);
	printf("After compress: %s\n", compress2(deDup));
}
