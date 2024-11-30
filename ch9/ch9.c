/*
// example_9-1.c
#define MAX 5
#include <stdio.h>

int main() {
	int i, sum = 0; double average;
	int rabbit[MAX];

	printf("Enter weights of five rebbits.\n");
	for (i = 0; i < MAX; i++)
		scanf("%d", &rabbit[i]);

	for (i = 0; i < MAX; i++)
		sum += rabbit[i];
	printf("Average weight is %.3lf.\n", ((double)sum) / MAX);

	printf("&rabbit[0] is %p.\n", &rabbit[0]);
	printf("&rabbit[0] is %p.\n", &rabbit[1]);
	printf("rabbit is %p.\n", rabbit);

	return 0;
}
*/

/*
// example_9-2.c
#define MAX 200
#include <stdio.h>

int main() {
	int i, num;
	int fib[MAX];

	printf("Enter a number N.\n");
	scanf("%d", &num);

	fib[0] = fib[1] = 1;
	for (i = 2; i <= num; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	printf("%dth fibonacci number is %d.\n", num, fib[i - 1]);

	return 0;
}
*/
