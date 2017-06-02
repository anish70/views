#include <iostream>
#include <string>

using namespace std;

void
permutate(string words[], int depth, string result)
{
	if (depth == words->length()){
		cout << result.c_str() << endl;	
	} else {
		string w = words[depth];
 		for (int i = 0; i < w.length(); i++){
			permutate(words, depth + 1, result + w.at(i));
		}
	}
}
 
int main()
{
	string words[] = {"red", "fox", "super"};
	permutate(words, 0, "");
}

