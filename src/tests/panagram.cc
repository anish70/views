#include <ctype.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


int
is_panagram(string &word)
{
	static const char arr[]  = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                        'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
                        'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                        'y', 'z', '0'};
	vector<char> alphabet(arr, arr + sizeof(arr) / sizeof(arr[0]) );
	char c; 

	cout << "Word: " << word.c_str() << " Leng : " << word.length()  << endl;
	for (size_t i = 0; i < word.length(); i++) {
		c = tolower(word.at(i)); 
		for (vector<char>::iterator it = alphabet.begin() ; it != alphabet.end(); ++it) {
			if ((*it) == c) {
				alphabet.erase(it);
			}
		}
	}

	return(alphabet.size() -1);
}
 
int main()
{
	string word = "The quick brown fox jumps over the little lazy dog";
	printf("%d\n", !is_panagram(word));

	word = "The quick brown fox jumps over the little lay dog";
	printf("%d\n", !is_panagram(word));
}


