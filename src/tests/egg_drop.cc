#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

using std::string;
using std::ifstream;

int breakingPoint = 0;
int countDrops = 0;

bool drop(int floor) {
	++countDrops;
	return floor >= breakingPoint;
}


int findBreakingPoint(int floors) {
	int interval = 14;
	int prevFloor = 0;
	int egg1 = interval;

	while (!drop(egg1) && egg1 <= floors) {
		interval -= 1;
		prevFloor = egg1;
		egg1 += interval;
	}

	int egg2 = prevFloor + 1;
	while (egg2 < egg1 && egg2 <= floors && !drop(egg2)) {
		egg2++;
	}

	return egg2 > floors ? -1 : egg2;
	
}

int
main(void)
{
	int num = findBreakingPoint(100);
	std::cout << "Breaking Floor = " << num << std::endl;
	return 0;
}
