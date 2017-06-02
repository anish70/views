#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <algorithm>
 
using namespace std;
 
int main (int argc, char *argv[])
{
	const string default_dictfile = "/usr/share/dict/words";
	string dictfile, buffer, sorted;
	ifstream ifs;
	map<string, list<string> *> wmap;
	list<string> *wlist;
	map<string, list<string> *>::iterator wmit;
 
	//Open the file
	if (argc < 2) {
		cout << "Using default dictionary: \"" << default_dictfile << endl;
		dictfile = default_dictfile;
	} else if (argc == 2) {
		dictfile = argv[1];
		cout << "Using dictfile: \"" << dictfile << endl;
	} else {
		cout << "Usage: " << argv[0] << " [dictfile]" << endl;
		exit (0);
	}
 
	ifs.open (dictfile.c_str (), fstream::in);
	if (!ifs.good ()) {
		cerr << "Error opening file \"" << dictfile << "\"" << endl;
		exit (1);
	}
 
	//Load file
	cout << "Loading file" << endl;
	int count = 0;
	while (ifs.good ()) {
		//Get current string into buffer
		ifs >> buffer;
 
		//Transform each character to lowercase and sort the characters in the string
		sorted = buffer;
		transform (sorted.begin (), sorted.end (), sorted.begin (), ::tolower);
		sort (sorted.begin (), sorted.end ());
 
		//Key into map to get the linked list of words with the same sorted order
		wmit = wmap.find(sorted);
		if (wmit == wmap.end ()) {
			//If the entry is empty, make a new linked list and insert
			//the pointer of this new list into the map keyed by the
			//sorted string
			wlist = new list<string> ();
			wmap.insert (pair<string, list<string> *> (sorted, wlist));
		} else {
			//If we already have a linked list there, then extract it
			wlist = wmit->second;
		}

		//Add the new word to the list we fetched from the map
		//Note that we need to create an object and add the newly created object
		wlist->push_front (string(buffer));
		++count;
	}
	cout << "File loaded, after: " << count  << endl;

	ifs.close ();
 
	//Find jumble
	while (1) {
		//Get input
		cout << "Enter jumble (\"q\" to quit): ";
		cin >> buffer;
 
		//Transform each character to lowercase and sort the characters in the string
		transform(buffer.begin (), buffer.end (), buffer.begin (), ::tolower);
		if (buffer == "q") {
			break;
		}

		sort (buffer.begin (), buffer.end ());
 
		//Find the linked list in the map with the list of words consisting of the
		//same sorted pattern
		wmit = wmap.find (buffer);
		if (wmit == wmap.end ()) {
			cout << "Not found" << endl;
		} else {
			//If found, then get the list and print every element of the list
			wlist = wmit->second;
			for (list<string>::iterator it = wlist->begin ();
					it != wlist->end (); it++) {
				cout << *it << ", ";
			}
      			cout << "\b\b" << endl;
		}
	}
 
	//Iterate over each element of the map and delete the lists, which we allocated before
	cout << "Freeing memory" << endl;
	for (map<string, list<string> *>::iterator it = wmap.begin ();
			it != wmap.end (); it++) {
		delete it->second;
	}
 
	cout << "End" << endl;
	return 0;
}
