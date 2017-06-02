#include <stdio.h>

void
fibonacci(int x) {
	int val = 0;
	int f[x+1];

	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i < x; i++)
		f[i] = f[i - 2] + f[i - 1];

	for (int i = 0; i < x; i++)
		printf("%d ", f[i]);
}

int
main() {
	unsigned int x;

	printf("Input the count (>0) of fibonacci numbers: ");
	scanf("%d", &x);

	printf("fibonacci sequence: ");
	(void)fibonacci(x);
	printf("\n");
	return 0;
}
