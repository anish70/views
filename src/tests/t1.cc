#include <stdio.h>

#if 0
int main()
{
int *a, *c;
*a = 4;
*c = *a;
printf("%d", c);
return 0;
}
#endif

int main (int argc, char *argv)
{
    for(int i=0; i<argc; i++)
        printf("%s ", argv[i]);

return 0;
}

