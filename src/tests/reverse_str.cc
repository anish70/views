#include <stdio.h>
#include <string.h>
 
char *reverse(char *s)
{
	char temp;
        char *start = s;
        char *end = s + strlen(s) - 1;
 
        for (; end > start; --end, start++) {
                temp = *start;
                *start = *end;
                *end = temp;
        }

        return s;
}
 
int
main(int argc, char *argv[])
{
        for (int i = 1; i < argc; i++) {
                printf("%s\n", reverse(argv[i]));
        }
}
