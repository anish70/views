#include<stdio.h>
 
void main() {
 
   int a = 3, b = 3, c;
 
   asm {
      mov ax,a
      mov bx,a
      add ax,bx
      mov c,ax
   }
 
   printf("%d",c);
}
