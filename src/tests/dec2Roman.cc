#include <iostream>
#include <string>

using namespace std;

void
decToRoman(int num)
{  
	// These are the key value in Roman counting  
	int val[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

	//Symbols for key values  
	string symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	int keyCount,i = 0;                    
	while (num){      
		//the number of times key value will appear in the Roman representation               
		keyCount=num/val[i];
		while (keyCount--) {        
            		cout << symbols[i];
		}  
		num %= val[i];  
		i++;
	}  
}  

int main()
{  
	int num;  
	cout << "Enter a decimal number: ";  
	cin >> num;
	cout << "The Roman number representation of the number is: ";
	decToRoman(num);
	cout << endl;  
	return 0;  
}  

