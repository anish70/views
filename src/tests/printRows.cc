#include <iostream>
using namespace std;

void print_stars(int rows, int index) {
	// 1 to r-i
        for (int space = 1; space <= rows - index; ++space) cout << "  ";
	// 0 to 2i-1
        for (int k = 0; k != 2*index -1; ++k) cout << "* "; 
        cout<<"\n";
}

void print_matrix(int rows) {
    for(int i=1;i<=rows;++i) // 1 to n
        print_stars(rows, i);

    for(int i=rows-1;i>=1;--i) // n-1 to 1
        print_stars(rows, i);
}

int main()
{
	int rows;
	cout<<"Enter the number of rows: ";
	cin>>rows;
	print_matrix(rows); 
}

