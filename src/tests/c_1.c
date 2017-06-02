#include <stdio.h>
#include <string.h>


const int limit = 10;

int
main(void)
{
	printf("Before: limit = %d\n", limit);
	const int * limitp = &limit; int i=27;
	limitp = &i;
	printf("After: limit = %d\n", limit);

	if (-1 < (unsigned char) 1 )
		printf(“-1 is less than (unsigned char) 1: ANSI semantics “);
	else
		printf(“-1 NOT less than (unsigned char) 1: K&R semantics “);
}
