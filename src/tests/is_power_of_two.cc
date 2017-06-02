
#include <iostream>
 
using namespace std;
 
int isPowerOfTwo (unsigned int x)
{
	printf("value: %d\n", x & (x - 1));

	return ((x != 0) && !(x & (x - 1)));
}

int
main(int argc, char *argv[])
{
        for (int i = 1; i < argc; i++) {
                printf("Number: %d, is power of two = %d\n",
			atoi(argv[i]), isPowerOfTwo(atoi(argv[i])));
        }
}



