#include <iostream>
 
using namespace std;

/* getMissingNo takes array and size of array as arguments*/
int getMissingNo (int a[], int how)
{
	int total  = (how+2)*(how+1)/2;   
	for (int i = 0; i< how; i++)
	       total -= a[i];
	return total;
}
 
int getMissingNo2(int a[], int how)
{
	int i;
	int x1 = a[0]; /* For xor of all the elemets in arary */
	int x2 = 1; /* For xor of all the elemets from 1 to n+1 */
     
	for (i = 1; i< how; i++)
		x1 = x1^a[i];
            
	for ( i = 2; i <= how+1; i++)
		x2 = x2^i;         
    
	return (x1^x2);
}
 
int main()
{
	int a[] = {1, 2, 4, 5, 6, 7, 8, 9, 10 , 12, 11, 14, 13, 18, 17, 16, 15, 20, 19,3,24,22,23,30,29,28,27,21,26 };
	int total = sizeof(a)/sizeof(a[0]);

	cout << "Missing Number is: " << getMissingNo(a, total) << endl;
	cout << "Missing Number is: " << getMissingNo2(a, total) << endl;
}
