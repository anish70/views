#include <iostream>
using namespace std;

int numberofTwos(int n) {
	int count = 0;
	while (n > 0) {
		if (n %10 == 2)
			count ++;
		n /= 10;
	}

	return count;
}

int CountTwos(int n) {
	int count = 0;
	for (int i = 2; i <= n; i++) {
		count += numberofTwos(i);
	}

	return count;
}

int main()
{
	int num;

	cout << "Give me a number? ";
	cin >> num;

	cout << CountTwos(num) << endl;
}
