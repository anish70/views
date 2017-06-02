#include <stdio.h>
#define LINE_LENGTH 81

int main(void)
	{   char data[LINE_LENGTH];
	FILE *f1 = fopen("print_me.c","r");
    
	while ( fgets(data,LINE_LENGTH, f1) != NULL ) {
		printf("%s",data);
	}
	return 0;
}
