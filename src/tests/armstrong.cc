#include <iostream>

using namespace std;

bool armstrong(int a, int b, int c) {

	int result = a*a*a+b*b*b+c*c*c;
	int val = a*100+b*10+c;
	return result == val;	
}

int main()
{
	for (int i = 1; i <= 10; i++)
		for (int j = 0; j <= 10; j++)
			for (int k = 0; k <= 10; k++)
				if (armstrong(i, j, k))
					cout << " " << i << " " <<  j << " " << k << endl;

}
