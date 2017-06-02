
#include <iostream>
 
using namespace std;

int fib1(int num) {
	if (num <= 1)
		return num;

	return fib1(num -1) + fib1(num -2);
}
 
int fib2(int n) {
  int f[n+1];
  f[0] = 0; f[1] = 1;
 
  for (int i = 2; i <= n; i++)
      f[i] = f[i-1] + f[i-2];
 
  for (int i = 0; i < n; i++)
	printf("%d ", f[i]);
  printf("\n");

  return f[n];
}

int main(int argc, char **argv)
{
	if (argc < 1) return -1;
	int num = atoi(argv[1]);

	// printf("Fib1 of %d = %d\n", num, fib1(num));
	fib2(num);
}


