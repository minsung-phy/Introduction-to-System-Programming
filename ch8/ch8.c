/*
// example_8-1.c
#include <stdio.h>

int square(int m) {
	return m * m;
}

int sq_add(int f, int s) {
	int total;
	total = square(f) + square(s);
	return total;
}

int main() {
	int first, second, sum;
	printf("Enter two integers.\n");
	scanf("%d%d", &first, &second);
	sum = sq_add(first, second);
	printf("The result is %d.\n", sum);

	return 0;
}
*/

/*
// example_8-2.c
#include <stdio.h>

void try(int a, int b) {
	printf("Inside try, a at %p, b at %p.\n", &a, &b);
	printf("Inside try, a = %d, b = %d.\n", a, b);
	a++; b++;
	printf("Upon increasing, a = %d, b = %d.\n\n", a, b);

	return;
}

int main() {
	int one = 1, two = 2;
	printf("In main, one at %p, two at %p.\n", &one, &two);
	printf("In main, one = %d, two = %d.\n\n", one, two);

	try(one, two);

	printf("Back to main, one at %p, two at %p.\n", &one, &two);
	printf("Back to main, one = %d, two = %d.\n\n", one, two);

	return 0;
}
*/

/*
// example_8-3.c
#include <stdio.h>

void sum_up(int n) {
	int sum = 0;
	sum += n;
	printf("Accumulated sum is %d.\n", sum);
}

int main() {
	int num, i;
	for (i = 1; i < 4; i++) {
		printf("Enter an integer.\n");
		scanf("%d", &num);
		sum_up(num);
	}

	return 0;
}
*/

/*
// example_8-4.c 
#include <stdio.h>

int sum;

void sum_up(int n) {
	sum += n;
	printf("Accumulated sum is %d.\n", sum);
}

int main() {
	int num, i; sum = 0;

	for (i = 1; i < 4; i++) {
		printf("Enter an integer.\n");
		scanf("%d", &num);
		sum_up(num);
	}
	
	printf("Finally, the sum is %d.\n", sum);

	return 0;
}
*/

/*
// example_8-5.c 
#include <stdio.h>

int main() {
	int i = 1;
	{
		printf("printing from 1 to 3.\n");
		int count = i;
		while (count < 4)
			printf("%d ", count++);
		printf("\n");
		printf("%d\n", count);
	}
	
	// printf("%d\n", count); // count를 정의된 블록 밖에서 사용했기 때문에 오류 발생

	return 0;
}
*/

/*
// example_8-6.c
#include <stdio.h>

void sum_up(int n) {
	static int sum = 0;

	sum += n;
	printf("Accumulated sum is : %d.\n", sum);
}

int main() {
	int num, i;

	for (i = 1; i < 4; i++) {
		printf("Enter an integer.\n");
		scanf("%d", &num);
		sum_up(num);
	}

	return 0;
}
*/

/*
// example_8-7.c
#include <stdio.h>

int a; double b; char c;

int main() {
	static int d;
	int e;
	printf("%d, %lf, %x, %d\n", a, b, c, d);
	// printf("%d\n", e); // 초기화되지 않은 지역변수 e를 사용하였으므로 오류 발생

	return 0;
}
*/

/*
// example_8-8.c
#include <stdio.h>

void increment(int m) {
	m++;
	printf("Inside function, m is %d.\n", m);
	
	return;
}

int main() {
	int a = 10;
	printf("Before calling function, a is %d.\n", a);
	increment(a);
	printf("After calling function, a is %d.\n", a);
	
	return 0;
}
*/

/*
// example_8-9.c
#include <stdio.h>

int increment(int m) {
	m++;
	printf("Inside function, m is %d.\n", m);

	return m;
}

int main() {
	int a = 10;
	printf("Before calling function, a is %d.\n", a);
	a = increment(a);
	printf("After calling function, a is %d.\n", a);

	return 0;
}
*/

/*
// example_8-10.c
#include <stdio.h>

void swap(int m, int n) {
	int temp;
	printf("Before swap, m = %d and n = %d.\n", m, n);
	temp = m;
	m = n;
	n = temp;
	printf("After swap, m = %d and n = %d.\n", m, n);
	return;
}

int main() {
	int a = 10, b = 20;
	printf("Before calling function, a = %d amd b = %d.\n", a, b);
	swap(a, b);
	printf("After calling function, a = %d amd b = %d.\n", a, b);

	return 0;
}
*/

/*
// example_8-11.c
#include <stdio.h>

inline int add(int a, int b) {
	return (a + b);
}

int main() {
	int sum, first = 10, second = 20;
	sum = add(first, second);
	printf("sum is %d.\n", sum);

	return 0;
}
*/

/*
// example_8-12.c
#include <stdio.h>

int power2(int num, int power) {
	__asm {
		mov eax, num;
		mov ecx, power;
		shl eax, cl;
	}
}

int main(void) {
	printf("3 times (2 to the 5) is %d.\n", power2(3, 5));
	return 0;
}
*/

/*
// example_8-13.c
#include <stdio.h>
#include <stdarg.h>

int find_min(int count, ...) {
	int min, temp, i;

	va_list(p);
	va_start(p, count);
	min = va_arg(p, int);
	for (i = 2; i <= count; i++) {
		temp = va_arg(p, int);
		if (temp < min)
			min = temp;
	}
	va_end(p);
	
	return min;
}

int main() {
	int arg_count = 3;
	printf("Minimum is %d.\n", find_min(arg_count, 30, 20, 10));

	return 0;
}
*/

/*
// example 8_14.c
#include <stdio.h>

int factorial(int n) {
	if (n == 1)
		return 1;
	else
		return (n * factorial(n - 1));
}

int main() {
	int num;
	printf("Enter a positive integer.\n");
	scanf("%d", &num);
	printf("Factorial of %d is %d.\n", num, factorial(num));

	return 0;
}
*/

/*
// example 8_15.c
#include <stdio.h>

void recurse(int n) {
	if (n == 0)
		return;
	else {
		printf("%d ", n);
		recurse(n - 1);
	}
}

int main() {
	int num;
	printf("Enter a positive integer.\n");
	scanf("%d", &num);
	recurse(num);

	return 0;
}
*/

/*
// example 8_16.c
#include <stdio.h>

void recurse(int n) {
	if (n == 0)
		return;
	else {
		recurse(n - 1);
		printf("%d ", n);
	}
}

int main() {
	int num;
	printf("Enter a positive integer.\n");
	scanf("%d", &num);
	recurse(num);

	return 0;
}
*/

/*
// example 8_17.c
#include <stdio.h>

void recurse(int n) {
	if (n == 0)
		return;
	else {
		printf("%d", n % 10);
		recurse(n / 10);
	}
}

int main() {
	int num;
	printf("Enter a positive integer.\n");
	scanf("%d", &num);
	recurse(num);
	printf("\n");

	return 0;
}
*/

/*
// example 8_18.c
#include <stdio.h>

void recurse(int n) {
	if (n != 0) {
		printf("%d", n % 10);
		recurse(n / 10);
	}
}

int main() {
	int num;
	printf("Enter a positive integer.\n");
	scanf("%d", &num);
	recurse(num);
	printf("\n");

	return 0;
}
*/

/*
// example 8_19.c
#include <stdio.h>

void to_binary(int n) {
	if (n == 0)
		return;
	else {
		to_binary(n / 2);
		printf("%d", (n % 2));
	}
}

int main() {
	int num;
	printf("Enter a positive integer.\n");
	scanf("%d", &num);
	to_binary(num);
	printf("\n");

	return 0;
}
*/

/*
// example 8_20.c
#include <stdio.h>

void reverse_it() {
	char ch;
	scanf("%c", &ch);
	if (ch == '\n')
		return;
	else {
		reverse_it();
		printf("%c", ch);
	}
}

int main() {
	printf("Enter a sentence.\n");
	reverse_it();
	printf("\n");

	return 0;
}
*/

/*
// example 8_21.c
#include <stdio.h>

int fib(int n) {
	if (n < 3)
		return 1;
	else
		return (fib(n - 1) + fib(n - 2));
}

int main() {
	int num;
	printf("Enter a number N.\n");
	scanf("%d", &num);
	printf("%dth fibonacci number is %d.\n", num, fib(num));

	return 0;
}
*/

/*
// example 8_22.c
#include <stdio.h>

long long fib(long long n) {
	if (n < 3)
		return 1;
	else
		return (fib(n - 1) + fib(n - 2));
}

int main() {
	long long num;
	printf("Enter a number N.\n");
	scanf("%lld", &num);
	printf("%lldth fibonacci number is %lld.\n", num, fib(num));

	return 0;
}
*/

/*
// example 8_23.c
#include <stdio.h>

int factorial(int n) {
	int i, fact = 1;
	for (i = n; i > 0; i--)
		fact *= i;
	return fact;
}

int main() {
	int num;
	printf("Enter a positive integer.\n");
	scanf("%d", &num);
	printf("Factorial of %d is %d.\n", num, factorial(num));

	return 0;
}
*/
