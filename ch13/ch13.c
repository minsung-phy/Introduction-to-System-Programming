/*
// example_13-1.c
#include "ch13.h"
#include <stdio.h>

int main() {
    struct car mycar = {"sonata", 2015, 120000};

    printf("Name is %s.\n", mycar.name);
    printf("Year is %d.\n", mycar.year);
    printf("Mileage is %d.\n", mycar.mileage);

    printf("&mycar is %p.\n", &mycar);
    printf("&(mycar.year) is %p.\n", &(mycar.year));

    printf("Enter the mileage updates.\n");
    scanf("%d", &mycar.mileage);
    printf("The new mileage is %d.\n", mycar.mileage);

    if (mycar.mileage > 150000)
        printf("It's old.\n");
    else
        printf("It's not that old.\n");

    return 0;
}
*/

/*
// example_13-2.c
#include "ch13.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct rectangle * p;
    int x_diff, y_diff;

    p = (struct ractangle *)malloc(sizeof(struct rectangle));
    if (p == NULL) {
        printf("No more memory.\n");
        exit(1);
    }

    printf("Enter x, y of top left.\n");
    scanf("%d%d", &(p->tl).x, &(p->tl).y);
    printf("Enter x, y of bottom right.\n");
    scanf("%d%d", &(p->br).x, &(p->br).y);

    x_diff = abs((p->br).x - (p->tl).x); // x 값의 차이
    y_diff = abs((p->br).y - (p->tl).y); // y 값의 차이
    printf("The area of rectangle is, %d.\n", x_diff * y_diff);

    return 0;
}
*/

/*
// example_13-3.c
#include <stdio.h>

int main() {
    struct first {
        short x;
        short y;
        short z;
    } a;

    struct second {
        float x;
        char y;
    } b;

    struct third {
        char x;
        double y;
        char z;
    } c;

    struct fourth {
        char x;
        char z;
        double y;
    } d;

    printf("sizeof(a) is %d.\n", sizeof(a));
    printf("sizeof(b) is %d.\n", sizeof(b));
    printf("sizeof(c) is %d.\n", sizeof(c));
    printf("sizeof(d) is %d.\n", sizeof(d));

    return 0;
}
*/

/*
// example_13-4.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct employee {
    char * name; // 구조체 멤버 변수로 사용된 포인터
    int resident_no;
};

int main() {
    struct employee seller, * p;
    p = &seller;
    p->name = "Jay kim";
    puts(p->name);

    p->name = (char*)malloc(sizeof(char) * 40);
    if (p->name == NULL) {
        printf("No more memory.\n");
        exit(1);
    }

    strcpy(p->name, "John Lee");
    puts(p->name);
    free(p->name);

    return 0;
}
*/

/*
// example_13-5.c
#include <stdio.h>

struct point {
    int x;
    int y;
};

struct point increment(struct point s) {
    s.x += 1;
    s.y += 1;
    return s;
}

int main() {
    struct point a = {1, 1}, b, c;

    b = a;
    printf("b is (%d, %d).\n", b.x, b.y);

    c = increment(a);
    printf("c is (%d, %d).\n", c.x, c.y);

    if (a.x == b.x && a.y == b.y)
        printf("a and b have same values.\n");
    if (&a == &b)
        printf("a and b are same points.\n");
    
    return 0;
}
*/

/*
// example_13-6.c
#include <stdio.h>

struct person {
    char name[10];
    int age;
};

int over_twenty(const struct person *p) {
    if (p->age > 20)
        return 1;
    else
        return 0;
}

int main() {
    struct person s1, s2 = {"Jay", 24};

    s1 = s2;
    printf("s1's name is %s.\n", s1.name);

    if (over_twenty(&s1))
        printf("%s is over twenty.\n", s1.name);
    
    return 0;
}
*/

/*
// example_13-7.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct employee {
    int entry_year; // 입사 연도
    char residence[6]; // 거주지
    char * name; // 사원 이름
};

int main() {
    struct employee a = {2019, "Seoul", NULL};
    struct employee b;

    a.name = (char*)malloc(5*sizeof(char));
    strcpy(a.name, "Lee");

    b = a;
    strcpy(b.name, "Park");

    printf("%d %s %s\n", a.entry_year, a.residence, a.name);
    printf("%d %s %s\n", b.entry_year, b.residence, b.name);

    return 0;
}
*/

/*
// example_13-8.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct employee {
    int entry_year;
    char residence[6];
    char * name;
};

void show_name(struct employee her) {
    printf("%s\n", her.name);
    strcpy(her.name, "홍두루미");
}

int main() {
    struct employee a = {2019, "Seoul", NULL};
    a.name = (char*)malloc(9*sizeof(char));
    strcpy(a.name, "박하영");

    show_name(a);
    printf("%s\n", a.name);
    return 0;
}
*/

/*
// example_13-9.c
#include <stdio.h>

int main() {
    int i;
    int entry[3] = {201504, 202011, 202502}; // 입사 연월
    char name[3][20] = {"Kim", "Lee", "Park"}; // 이름
    char phone[3][15] = {"02-1234", "031-1234", "051-1234"}; // 전번

    for (i = 0; i < 3; i++)
        printf("%d %s %s.\n", entry[i], name[i], phone[i]);
    
    return 0;
}
*/

/*
// example_13-10.c
#include <stdio.h>

struct employee {
    int entry;
    char name[20];
    char phone[15];
};

int main() {
    int i;
    struct employee arr[3] = 
    {
        {201504, "Kim", "02-1234"},
        {202011, "Lee", "031-1234"},
        {202502, "Park", "051-1234"}
    };

    for (i = 0; i < 3; i++)
        printf("%d %s %s.\n", arr[i].entry, arr[i].name, arr[i].phone);
    
    return 0;
}
*/

/*
// example_13-13.c
#include <stdio.h>

void test() {
    #define TRUE 1
    typedef int* ptrType;
    int num = 10;
    ptrType p = &num;
    printf("%d\n", *p);
}

int main() {
    // ptrType p; // 컴파일 오류
    test();
    printf("%d\n", TRUE);

    return 0;
}
*/