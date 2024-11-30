/*
// example_10-1.c
#include <stdio.h>

int main() {
	int num, *p;

	p = &num; // p에 주소 값 저장
	*p = 5; // *p로 간접 참조를 하여 값 저장

	printf("&num = %p, num = %d.\n", &num, num);
	printf("p = %p, *p = %d, &p = %p\n", p, *p, &p);
	
	printf("sizeof(p) = %d.\n", sizeof(p)); // 포인터 변수 자체의 크기로서 8바이트
	printf("sizeof(*p) = %d.\n", sizeof(*p)); // 포인터 변수가 가리키는 변수의 크기로서 4바이트

	return 0;
}
*/

/*
// example_10-2.c
#include <stdio.h>

int main() {
	int first = 50, second = 200, * p;

	printf("&first is %p.\n", &first);
	printf("&p is %p.\n", &p);

	p = &first;
	printf("p is %p.\n", p);
	printf("*p is %d.\n", *p);

	*p += 50;
	printf("*p changed to %d.\n", *p);

	p = &second;
	printf("*p changed to %d.\n", *p);

	return 0;
}
*/

/*
// example_10-3.c
#include <stdio.h>

void call_by_value(int p) {
	p += 1;
}

void call_by_reference(int* p) {
	*p += 1;
}

int main() {
	int num;

	num = 500;
	printf("Before call_by_value, num is %d.\n", num);
	call_by_value(num);
	printf("After call_by_value, num is %d.\n", num);

	num = 500;
	printf("Before call_by_reference, num is %d.\n", num);
	call_by_reference(&num);
	printf("After call_by_reference, num is %d.\n", num);

	return 0;
}
*/

/*
// example_10-4.c
#include <stdio.h>

void min_max(int a, int b, int* min, int* max) {
	if (a < b) {
		*min = a;
		*max = b;
	}
	else {
		*min = b;
		*max = a;
	}
}

int main() {
	int first, second, smaller, larger;
	printf("Enter two different integers.\n");
	scanf("%d%d", &first, &second);
	min_max(first, second, &smaller, &larger);
	printf("Smaller : %d, Larger : %d\n", smaller, larger);

	return 0;
}
*/

/*
// example_10-5.c
#include <stdio.h>

int* larger(int* a, int* b) {
	if (*a > *b)
		return a;
	else
		return b;
}

int main() {
	int first, second, *p;
	printf("Enter two different integers.\n");
	scanf("%d%d", &first, &second);
	p = larger(&first, &second);
	printf("%d is larger.\n", *p);

	return 0;
}
*/

/*
// example_10-6.c
#include <stdio.h>

void swap(int*, int*);

int main() {
	int first, second;
	printf("Enter two numbers to swap.\n");
	scanf("%d%d", &first, &second);
	printf("Before swap : first = %d and second = %d.\n", first, second);
	swap(&first, &second);
	printf("After swap : first = %d and second = %d.\n", first, second);

	return 0;
}

void swap(int* p, int* q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
*/

/*
// example_10-7.c
#define MAX 4
#include <stdio.h>

void increment(int rb[]) {
	int i;
	for (i = 0; i < MAX; i++)
		rb[i]++;
}

int main() {
	int i, rabbit[MAX] = { 10, 20, 30, 40 };
	increment(rabbit);
	for (i = 0; i < MAX; i++)
		printf("%d ", rabbit[i]);
	printf("\n");

	return 0;
}
*/

/*
// example_10-8.c
#define MAX 100
#include <stdio.h>

void print_array(const int arr[], int length) {
	int i;
	for (i = 0; i < length; i++)
		printf("%d ", arr[i]);
}

int main() {
	int i, temp, rabbit[MAX];
	printf("Enter an integer.\n");
	scanf("%d", &temp);
	for (i = 0; temp >= 0; i++) {
		rabbit[i] = temp;
		printf("Enter an integer.\n");
		scanf("%d", &temp);
	}
	print_array(rabbit, i);
	printf("\n");

	return 0;
}
*/

/*
// example_10-9.c
#define MAX 100
#include <stdio.h>

void print_array(const int arr[], int length);
void swap(int*, int*);
void selection_sort(int arr[], int length);

int main() {
	int i = 0, temp, data[MAX];
	printf("Enter integers seperated by a blank.\n");
	while (1) {
		scanf("%d", &temp);
		if (temp < 0)
			break;
		data[i++] = temp;
	}

	printf("Before sorting: ");
	print_array(data, i);
	printf("\n");

	selection_sort(data, i);
	printf("After sorting: ");
	print_array(data, i);
	printf("\n");

	return 0;
}

void print_array(const int arr[], int length) {
	int i;
	for (i = 0; i < length; i++)
		printf("%d ", arr[i]);
}

void swap(int* p, int* q) {
	int temp; 
	temp = *p;
	*p = *q;
	*q = temp;
}

void selection_sort(int arr[], int length) {
	int last, largest, current;

	for (last = length - 1; last > 0; last--) {
		largest = 0;
		for (current = 1; current <= last; current++) {
			if (arr[current] > arr[largest])
				largest = current;
		}
		swap(&arr[largest], &arr[last]);
	}
}
*/

/*
// example_10-10.c
#define MAX 100
#include <stdio.h>

void print_array(const int arr[], int length);
void swap(int*, int*);
void bubble_sort(int arr[], int length);

int main() {
	int i = 0, temp, data[MAX];
	printf("Enter integers seperated by a blank.\n");
	while (1) {
		scanf("%d", &temp);
		if (temp < 0)
			break;
		data[i++] = temp;
	}

	printf("Before sorting: ");
	print_array(data, i);
	printf("\n");

	bubble_sort(data, i);
	printf("After sorting: ");
	print_array(data, i);
	printf("\n");

	return 0;
}

void print_array(const int arr[], int length) {
	int i;
	for (i = 0; i < length; i++)
		printf("%d ", arr[i]);
}

void swap(int* p, int* q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void bubble_sort(int arr[], int length) {
	int pass, current;

	for (pass = 1; pass < length; pass++) {
		for (current = 0; current < (length - pass); current++) {
			if (arr[current] > arr[current + 1])
				swap(&arr[current], &arr[current + 1]);
			}
	}
}
*/

/*
// example_10-11.c 
#define MAX 100
#include <stdio.h>

void print_array(const int arr[], int length);
void swap(int*, int*);
void bubble_sort(int arr[], int length);

int main() {
	int i = 0, temp, data[MAX];
	printf("Enter integers seperated by a blank.\n");
	while (1) {
		scanf("%d", &temp);
		if (temp < 0)
			break;
		data[i++] = temp;
	}

	printf("Before sorting: ");
	print_array(data, i);
	printf("\n");

	bubble_sort(data, i);
	printf("After sorting: ");
	print_array(data, i);
	printf("\n");

	return 0;
}

void print_array(const int arr[], int length) {
	int i;
	for (i = 0; i < length; i++)
		printf("%d ", arr[i]);
}

void swap(int* p, int* q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void bubble_sort(int arr[], int length) {
	int pass, current, sorted = 0;
	// sorted : 이미 정렬이 되어 있는지를 확인하기 위한 플래그 변수

	for (pass = 1; (pass < length) && (!sorted); pass++) {
		sorted = 1;
		for (current = 0; current < (length - pass); current++) {
			swap(&arr[current], &arr[current + 1]);
			sorted = 0;
		}
	}
	// 일단 매 단계에 들어갈 때마다 이미 정렬이 되어 있다고 가정한다. 
	// 이어 루프 내에서 한 번이라고 스와핑이 있었으면 sorted 값을 거짓으로 바꾼다. 
	// 그렇지 않으면 초기화 값인 true가 그대로 유지되기 깨문에 바깥쪽 루프를 빠져나온다. 
	// 따라서 그 다음 단계로 넘어가지 않는다.
}
*/
