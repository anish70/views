#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>

using std::string;
using std::ifstream;

int
main(void)
{
	for (unsigned int i = 100; i > 0; i--) {
		printf("%u\n", i);
	}
	return 0;
}
