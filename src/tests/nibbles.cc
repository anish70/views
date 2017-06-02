#include<stdio.h>
#include<stdlib.h>

unsigned char nibble(unsigned char c)
{
	return(((c&0xf0)>>4)|((c&0x0f)<<4));  
}

int main(void)
{
	char c=0x2F; //Test subject of this program
	printf("\nTest Value is %x\n", c);
	printf("\nThe Swapped value is %x\n", nibble(c));
} 
