#include <vector>
#include <iostream>

using namespace std;

int
main(int argc, char *argv[])
{
	vector<int> v(100);
	for (int i = 0; i < 100; i++)
		v[i] = i;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl;

	for (int w: v) {
		cout << w << " ";
	}
	cout << endl;
}

