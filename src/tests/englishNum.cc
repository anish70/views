#include <iostream>
#include <string>
#include <list>
 
using namespace std;

string Ones[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
string tens[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
string bigs[] = { "", "Thousand", "Million", "Billion" };
string hundred = "Hundred";
string negative = "Negative";


string convert(int num)
{
	if (num == 0) {
		return Ones[num];
	} else if (num < 0) {
		return "Minus" + convert (-1 * num);
	}

	list<string> parts[20];

	while (num > 0) {
	}
	
	return Ones[1];
}

int main(int argc, char **argv)
{
	int first;
	cout << "Enter the number: ";
	cin  >> first;

	cout << "Number is: " << convert(first) << endl;
	return 0;
}


