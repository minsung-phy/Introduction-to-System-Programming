/*
// example_12-1.c
#include <stdio.h>

int main() {
	char* p = "apple";
	char str[20];
	int i;

	printf("*p is %c.\n", *p);
	printf("Last character of apple is %c.\n", *("apple" + 4));
	// "apple"은 'a'를 가리키는 포인터를 돌려줌.
	// 이에 4를 더하고 있으므로 이는 포인터 산술 연산임.

	printf("Enter a string.\n");
	scanf("%s", str);

	printf("%s\n", str);
	for (i = 0; str[i] != '\0'; i++)
		printf("%c", str[i]);
	printf("\n");
	
	return 0;
}
*/

/*
// example_12-2.c
#include <stdio.h>
#include <string.h>

int main() {
	char * str1 = "Okay Buddy";
	char str2[15] = "Bless you.";

	printf("strlen(str1) is %d.\n", strlen(str1));
	printf("strlen(str2) is %d.\n", strlen(str2));
	printf("sizeof(str1) is %d.\n", sizeof(str1));
	printf("sizeof(str2) is %d.\n", sizeof(str2));

	return 0;
}
*/

/*
// example_12-3.c
#include <stdio.h>

int main() {
	char str1[10] = "apple";
	char* str2 = "apple";
	
	str1[4] = 'y';
	printf("%s", str1);
	printf("\n");
	
	str2 = "pie";
	printf("%s", str2);
	printf("\n");

	// str2[4] = 'y'; // 실행 오류 (크래시)
	// str1 = "peach"; // 컴파일 오류 (좌변이 상수)

	return 0;
}
*/

/*
// example_12-4.c
#include <stdio.h>

char* get_apple() {
	char* p = "apple";
	return p;
}

int main() {
	char* str = get_apple();
	printf("%s", str);

	return 0;
}
*/

/*
// example_12-5.c
#define MAX 15
#include <stdio.h>

int main() {
	char ch, str[MAX];
	int i;

	printf("Enter a sentence to reverse.\n");
	for (i = 0; (ch = getchar()) != '\n'; i++)
		str[i] = ch;
	str[i] = '\0';

	for (--i; i >= 0; i--)
		putchar(str[i]);

	return 0;
}
*/

/*
// example_12-6.c
#define MAXCHAR 20
#include <stdio.h>
#include <ctype.h> // for islower, toupper

char* read_line() { // 입력 문장을 text 배열에 넣고 배열 시작 주소를 돌려줌
	char ch;
	int i;
	static char text[MAXCHAR]; // 함수를 빠져나가도 사라지지 않게 하기 위해 정적 변수로 선언

	printf("Enter a sentence.\n");
	for (i = 0; (ch = getchar()) != '\n'; i++)
		text[i] = ch;
	text[i] = '\0';
	
	return text;
}

int main() {
	int i;
	char* p = read_line();

	for (i = 0; p[i] != '\0'; i++) {
		if (islower(p[i]))
			p[i] = toupper(p[i]);
		putchar(p[i]);
	}
	printf("\n");

	return 0;
}
*/

/*
// example_12-7.c
#include <stdio.h>

void swap(char*, char*);
void permute(char*, int, int);

int main() {
	char str[] = "abc";
	permute(str, 0, strlen(str) - 1); // 1

	return 0;
}

void swap(char* x, char* y) {
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permute(char* s, int left, int right) { // 2
	int i;
	if (left == right) // 3
		printf("%s\n", s);
	else {
		for (i = left; i <= right; i++) { // 4
			swap(s + left, s + i); // 5 -> 스왑
			permute(s, left + 1, right); // 6 -> 재귀로 순열 구함
			swap(s + left, s + i); // 7 -> 백트래킹
		}
	}
}
*/

/*
// example_12-8.c
#include <stdio.h>

int main() {
	char str[128];

	printf("Enter a string.\n");
	scanf("%[A-Z]s", str);
	printf("String before lower case is %s\n", str);

	while (getchar() != '\n');
	printf("Enter a string.\n");
	scanf("%[^e]s", str);
	printf("String before e is %s\n", str);

	while (getchar() != '\n');
	printf("Enter a string with spaces.\n");
	scanf("%[^\n]s", str);
	printf("You entered %s\n", str);

	while (getchar() != '\n');
	printf("Enter a string with spaces.\n");
	gets(str);
	printf("You entered %s\n", str);

	return 0;
}
*/

/*
// example_12-9.c
#include <stdio.h>

int main() {
	char str[10];
	printf("Enter a string.\n");
	gets(str);
	puts(str);

	do {
		printf("Enter another string.\n");
		gets(str);
		puts(str);
	} while (*str != '\0');

	printf("Enter a very LONG string.\n");
	gets(str);
	printf("You entered,\n");
	puts(str);

	return 0;
}
*/

/*
// example_12-10.c
#include <stdio.h>
#include <string.h>

int main() {
	char text[10];

	printf("Enter a text.\n"); // 1
	fgets(text, sizeof(text), stdin); // 2
	printf("You entered %s.", text); // 3
	printf(" It's length is %d.\n", strlen(text)); // 4

	text[strlen(text) - 1] = '\0'; // 5
	printf("You entered %s.", text);
	printf(" It's length is %d.\n", strlen(text));

	return 0;
}
*/

/*
// example_12-11.c
#include <stdio.h>

int main() {
	char first[6], last[6];

	printf("Enter first name.\n");
	fgets(first, sizeof(first), stdin);

	// while (getchar() != '\n');

	printf("Enter last name.\n");
	fgets(last, sizeof(last), stdin);

	printf("Full name is,\n");
	puts(first);
	puts(last);
	
	return 0;
}
*/

/*
// example_12-12.c
#include <stdio.h>
#include <string.h>

int main() {
    char * str1 = "pine", * str2 = "apple";

    if (strlen(str1) - strlen(str2) >= 0)
        printf("yes.\n");
    else
        printf("no.\n");
    
    if (strlen(str1) > strlen(str2))
        printf("yes.\n");
    else
        printf("no.\n");

    if (((int)strlen(str1) - (int)strlen(str2)) >= 0)
        printf("yes.\n");
    else
        printf("no.\n");
     
    return 0;
}
*/

/*
// example_12-13.c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[30], str2[10];

    printf("Enter the first string.\n");
    gets(str1); 
    printf("Enter the second string.\n");
    gets(str2);
    // char * gets(char * str) : 한 줄 읽기 함수 
    // '\n'을 만나거나 파일 끝에 도달하면 읽기를 멈춤
    // 문자열 끝에 '\0'을 추가
    // 성공적이면 str을, 그렇지 않으면 NULL을 리턴

    printf("strlen(str1) is %d.\n", strlen(str1));
    printf("strlen(str2) is %d.\n", strlen(str2));
    // size_t strlen(const char * str) : 문자열의 길이를 리턴 ('\0' 제외)

    if (strcmp(str1, str2) == 0)
        printf("%s and %s are equal.\n", str1, str2);
    else if (strcmp(str1, str2) < 0)
        printf("%s is smaller than %s.\n", str1, str2);
    else
        printf("%s is bigger than %s.\n", str1, str2);
    // int strcmp(const char *str1, const char *str2);
    // str1이 가리키는 문자열과 str2가 가리키는 문자열 비교 
    // str1 > str2이면 양수, str1 < str2이면 음수, str1 == str2이면 0을 리턴

    printf("Before strcpy, str1 = %s, str2 = %s.\n", str1, str2);
    strcpy(str1, str2);
    printf("After strcpy, str1 = %s, str2 = %s.\n", str1, str2);
    // char* strcpy(char *dest, char *src);
    // strcpy 함수는 src가 가리키는 문자열을 dest가 가리키는 문자열로 복사한 다음 dest를 돌려준다. 
    // src 문자열 끝의 ‘\0’까지도 dest 문자열로 복사한다. 
    // strcpy 함수 실행 결과 dest 문자열은 ‘\0’을 처음 만나는 “apple”(src의 문자열)에서 끝나기 때문에 이후의 나머지 문자열은 모두 무시된다. 
    // 이 함수를 쓸 때에는 인자의 순서에 특히 유의해야 한다.
    // 뒤의 것이 앞의 것으로 복사된다. 다시 말해 나중 인자인 src가 가리키는 것을 처음 인자인 dest가 가리키는 곳으로 복사한다.

    printf("Before strcat, str1 = %s, str2 = %s.\n", str1, str2);
    strcat(str1, str2);
    printf("After strcat, str1 = %s, str2 = %s.\n", str1, str2);
    // char* strcat(char *dest, char *src)
    // strcat 함수는 문자열을 이어붙이는 함수로서 src가 가리키는 문자열을 dest가 가리키는 문자열 끝에 이어붙인 다음에 dest를 돌려준다. 
    // dest 문자열 끝 ‘\0’에서부터 src 문자열의 첫 문자가 덧씌워진다는 점에 유의해야 한다. 
    // 또, dest가 가리키는 배열이 src가 가리키는 문자열을 이어 붙이기에 충분한지도 확인해야 한다.

    printf("%s.\n", strcat(str1, "OMG!"));

    return 0;
}
*/

/*
// example_12-14.c
#include <stdio.h>

int my_strlen(const char * str) {
    int i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}

int main() {
    char text[30];
    printf("Enter a text.\n");
    gets(text);
    printf("Length of the text is %d.\n", my_strlen(text));

    return 0;
}
*/

/*
// example_12-15.c
#include <stdio.h>

int recursive_strlen(const char * str) {
    if (*str == '\0') 
        return 0;
    else
        return (1 + recursive_strlen(++str));
}

int main() {
    char text[30];
    printf("Enter a string.\n");
    gets(text);
    printf("Length is %d.\n", recursive_strlen(text));

    return 0;
}
*/

/*
// example_12-16.c 
#include <stdio.h>

char * my_strcpy(char * dest, const char * src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') // dest[i] = src[i]로 dest[i]에 src의 개별 요소 대입 
        i++;
    return dest;
}

int main() {
    char dest[30], src[10];

    printf("Enter destination string.\n");
    gets(dest);
    printf("Enter source string.\n");
    gets(src);

    printf("On strcpy(dest, src), dest became %s.\n", my_strcpy(dest, src));

    return 0;
}
*/

/*
// example_12-17.c
#include <stdio.h>

char * my_strcpy(char * dest, const char * src) {
    char * backup = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++; src++;
    }
    *dest = '\0';
    return backup;
}

int main() {
    char dest[30], src[10];

    printf("Enter destination string.\n");
    gets(dest);
    printf("Enter source string.\n");
    gets(src);

    printf("On strcpy(dest, src), dest became %s.\n", my_strcpy(dest, src));

    return 0;
}
*/

/*
// example_12-18.c
#include <stdio.h>
#include <string.h>

int main() {
    char * here, * there;
    char text[] = "This is first. This is second. This is third";
    const char ch = '.';
    here = strchr(text, ch);
    printf("Text after the first peroid is, %s\n", (here + 2));

    strcpy(text, "It is a right answer.");
    there = strstr(text, "right");
    strncpy(there, "wrong", 5);
    puts(text);

    return 0;
}
*/

/*
// example_12-19.c
#include <stdio.h>

int main() {
    char str[100];

    char * name = "Lee eun";
    int age = 19;
    double weight = 58.5;

    char * first = "First line of a long string.";
    char * second = "Second line of a long string.";

    sprintf(str, "Name: %s, Age: %d, Weight: %lf.", name, age, weight);
    puts(str);

    sprintf(str, "%s %s", first, second);
    puts(str);

    return 0;
}
*/

/*
// example_12-20.c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "J.Park Seoul 010-2222-3456";

    char * p = strtok(str, " ");
    while (p != NULL) {
        printf("%s\n", p);
        p = strtok(NULL, " ");
    }
    return 0;
}
*/

/*
// example_12-21.c 
#include <stdio.h>
#include <string.h>

int main() {
    int i;
    unsigned char str[40];

    printf("Enter a mixture of Korean and English.\n");
    gets(str);
    puts(str);

    for (i = 0; i < (int)strlen(str); i++) 
        printf("%c", str[i]);
    printf("\n");

    
    // 한글은 2바이트 단위로 하나의 문자를 나타내므로 2바이트 중 둘때 바이트를 먼저 찍고 이어서 첫째 바이트를 찍어서는 제대로 된 출력이 나오지 않음.
    // for (i = (int)strlen(str) - 1; i >= 0; i--) 
    //    printf("%c", str[i]);
    // printf("\n");
    

   for (i = (int)strlen(str) - 1; i >= 0; ) {
        if (str[i] >= 0 && str <= 127) {
            printf("%c", str[i]);
            i--;
        }
        else {
            printf("%c", str[i-1]);
            printf("%c", str[i]);
            i -= 2;
        }
   }
    printf("\n");

    return 0;
}
*/

/*
// example_12-22.c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "ABC언어";
    wchar_t uni_str[] = L"ABC언어";

    printf("sizeof(str) is %d.\n", sizeof(str));
    printf("sizeof(uni_str) is %d.\n", sizeof(uni_str));

    printf("strlen(str) is %d.\n", strlen(str));
    printf("wcslen(uni_str) is %d.\n", wsclen(uni_str));

    return 0;
}
*/

/*
// example_12-23.c
#include <stdio.h>

int main() {
    char str[4];
    
    printf("Enter a string.\n");
    scanf("%s", str);
    printf("After scanf, str became %s\n\n", str);

    return 0;
}
*/

/*
// example_12-24.c
#include <stdio.h>

int main() {
    char str[4];

    printf("Enter a string.\n");
    scanf_s("%s", str, sizeof(str));
    printf("After scanf_s str became %s\n", str);

    return 0;
}
*/

/*
// example_12-25.c
#include <stdio.h>
#include <string.h>

int main() {
    char dest[9];
    char * src = "mju.ac.kr";
    char str[9];

    strncpy(dest, src, sizeof(dest));
    printf("%s\n", strcpy(str, dest));

    return 0;
}
*/

/*
// example_12-26.c
#include <stdio.h>
#include <stdlib.h> // to use NULL
#include <string.h> // to use strcpy

char * safe_strcpy(char *, const char *);

int main() {
    char source[100];
    char * destination = NULL;

    printf("Enter source string.\n");
    gets(source);

    destination = safe_strcpy(destination, source);
    printf("After safe string copy, destination points to\n");
    puts(destination);
    free(destination);

    return 0;
}

char * safe_strcpy(char * dest, const char * src) {
    char * backup;

    dest = (char*)malloc(sizeof(char) * (strlen(src) + 1));
    if (dest == NULL) {
        printf("No more memory.\n");
        exit(1);
    }
    backup = dest;
    while (*dest++ = *src++);

    return backup;
}
*/

/*
// example_12-27.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * my_strcpy(char *, const char *);

int main() {
    char source[30], *destination = NULL;

    printf("Enter source string.\n");
    gets(source);
    destination = my_strcpy(destination, source);
    printf("After string copy, destination points to\n");
    puts(destination);
    free(destination);

    return 0;
}

char * my_strcpy(char * dest, const char * src) {
    dest = (char*)malloc(sizeof(char) * strlen(src) + 1);
    if (dest == NULL) {
        printf("No more memory.\n");
        exit(1);
    }

    memset(dest, 0, sizeof(char) * (strlen(src) + 1));
    memcpy(dest, src, sizeof(char) * (strlen(src) + 1));

    return dest;
}
*/

/*
// example_12-28.c
#define FRIENDS 3
#define MAX 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char * p, char * q) {
    char temp[MAX];
    strcpy(temp, p);
    strcpy(p, q);
    strcpy(q, temp);
}

void bubble_sort(char arr[FRIENDS][MAX]) {
    int pass, current, sorted = 0;
    for (pass = 1; (pass < FRIENDS) && (!sorted); pass++) {
        sorted = 1;
        for (current = 0; current < (FRIENDS - pass); current++) {
            if (strcmp(arr[current], arr[current + 1]) > 0)
                swap(arr[current], arr[current + 1]);
        }
    }
}

void print_array(char arr[FRIENDS][MAX]) {
    int i;
    printf("\n");
    for (i = 0; i < FRIENDS; i++)
    puts(arr[i]);
}

int main() {
    char name[MAX];
    char list[FRIENDS][MAX];
    int i;

    for (i = 0; i < FRIENDS; i++) {
        printf("Enter your friend's name.\n");
        gets(name);
        strcpy(list[i], name);
    }
    bubble_sort(list);
    print_array(list);

    return 0;
}
*/

/*
// example_12-29.c
#include <stdio.h>
#include <string.h>

int main() {
    int i;
    char conti[3][5] = {"Kim", "Lee", "Park"};
    char temp[5];

    char * ragged[3] = {"Kim", "Lee", "Park"};
    char * temp_ptr;

    strcpy(temp, conti[2]);
    strcpy(conti[2], conti[0]);
    strcpy(conti[0], temp);
    for (i = 0; i < 3; i++)
        printf("%s ", conti[i]);
    printf("\n");
    temp_ptr = ragged[2];
    ragged[2] = ragged[0];
    ragged[0] = temp_ptr;
    for (i = 0; i < 3; i++)
        printf("%s ", ragged[i]);
    printf("\n");

    return 0;
}
*/

/*
// example_12-30.c
#define MAX 10
#include <stdio.h>
#include <string.h>

int main() {
    char wish_list[MAX][100];
    char temp[100];
    int i = 0, j;

    while (1) {
        printf("Enter your wishes.\n");
        gets(temp);
        if (strcmp(temp, "quit") == 0)
            break;
        strcpy(wish_list[i], temp);
        i++;
    }
    for (j = 0; j < i; j++)
        puts(wish_list[i]);

    return 0;
}
*/

/*
// example_12-31.c
#define MAX 10
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char * wish_list[MAX];
    char temp[100];
    int i = 0, j;

    while (1) {
        printf("Enter your wishes.\n");
        gets(temp);
        if (strcmp(temp, "quit") == 0)
            break;
        wish_list[i] = (char*)malloc(sizeof(char)*(strlen(temp)+1));
        if (wish_list[i] == NULL) {
            fprintf(stderr, "No more memory.\n");
            exit(1);
        }
        strcpy(wish_list[i], temp);
        i++;
    }

    for (j = 0; j < i; j++)
        puts(wish_list[j]);
    for (j = 0; j < i; j++) {
        free(wish_list[j]);
        wish_list[j] = NULL;
    }

    return 0;
}
*/

/*
// example_12-32.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    int i;
    char * name = argv[1];
    int age = atoi(argv[2]);

    printf("argc is %d\n", argc);
    printf("%s is %d years old\n", name, age);

    for (i = 1; i < argc; i++)
        printf("%s ", argv[i]);
    printf("\n");

    return 0;
}
*/

/**/
// example_12-33.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char ** argv) {
    int i, max;
    int * rand_arr;

    srand(time(NULL));
    max = atoi(argv[1]);

    rand_arr = (int*)malloc(max * sizeof(int));
    if (rand_arr == NULL) {
        fprintf(stderr, "No more memory.\n");
        exit(1);
    }

    for (i = 0; i < max; i++)
        *(rand_arr + i) = 1 + rand() % 45;
    for (i = 0; i < max; i++)
        printf("%d ", *(rand_arr + i));
    printf("\n");

    free(rand_arr);

    return 0;
}