#include <iostream>
#include <string>

using namespace std;

char* Itoa(int val, int base){
	
	static char buf[32] = {0};
	
	int i = 30;
	
	for(; val && i ; --i, val /= base)
	
		buf[i] = "0123456789abcdef"[val % base];
	
	return &buf[i+1];
	
}

int Atoi(char *str)
{
	int n = 0;
	int i=0;

	while(str[i]) {
		n *= 10;
		n += str[i] - '0';
		++i;
	}

	return n;
}

int main()
{
	char s[] = "4215";

	int val = Atoi(s);

	cout << val << endl;
	char *out = Itoa(val, 10);
	cout << out << endl;
}
