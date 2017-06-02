#include <iostream>
using namespace std;
 
#include <iomanip>
using std::setw;
 

// function to generate and retrun random numbers.
int * getRandom( )
{
  static int  r[10];

  // set the seed
  srand( (unsigned)time(NULL) );
  for (int i = 0; i < 10; ++i) {
    r[i] = rand();
  }

  return r;
}


int main ()
{
   int n[ 10 ]; // n is an array of 10 integers
 
   // initialize elements of array n to 0          
   for ( int i = 0; i < 10; i++ ) {
      n[ i ] = i + 100; // set element at location i to i + 100
   }
   cout << "Element" << setw(6) << "Value" << endl;
 
   // output each array element's value                      
   for ( int j = 0; j < 10; j++ ) {
      cout << setw( 7 )<< j << setw(6) << n[ j ] << endl;
   }
 
   // an array with 5 rows and 2 columns.
   int a[5][2] = { {9,9}, {8,8}, {7,7}, {6,6},{5,5}};
 
   // output each array element's value                      
   for ( int i = 0; i < 5; i++ ) {
      for ( int j = 0; j < 2; j++ ) {
         // cout << "a[" << i << "][" << j << "]: " << a[i][j]<< endl;
      }
    }

   // a pointer to an int.
   int *p = getRandom();
   for ( int i = 0; i < 10; i++ ) {
       cout << "*(p + " << i << ") : " << setw(16) << *(p + i) << endl;
   }


   return 0;
}
