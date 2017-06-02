#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// print last K lines
void
print_lastK_lines(const char *fileName, int lineNum)
{
	const int K = lineNum;
	ifstream file(fileName);
	string L[4];
	int size = 0;

	while (file.peek() != EOF) {
		getline(file, L[size%K]);
		size++;
	}

	int start = size > K ? size % K : 0;
	int count = min(size, K);

	for (int i = 0; i < count; i++) {
		cout << L[(start+i)%K] << endl;
	}
}

int
main(void)
{
	print_lastK_lines("data.txt", 4); 
	return 0;
}

