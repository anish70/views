#include<iostream>
#include<cstring>
using namespace std;
 
bool isSubSequence(char str1[], char str2[], int m, int n)
{
   int j = 0; // For index of str1 (or subsequence
 
   // Traverse str2 and str1, and compare current character 
   // of str2 with first unmatched char of str1, if matched 
   // then move ahead in str1

   for (int i=0; i<n && j<m; i++) {
		if (str1[j] == str2[i]) {
			j++;
		}
    }
 
   // If all characters of str1 were found in str2
   return (j==m);
}
 
int main()
{
	char str1[] = "gksrek";
	char str2[] = "geeksforgeeks";
	isSubSequence(str1,
			str2,
			strlen(str1),
			strlen(str2)) ? cout << "Yes \nt": cout << "No\n";
	return 0;
}
