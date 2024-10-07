#include <stdio.h>

int main()
{
    short width;
    int height;
    float area;

    double total;
    int length;
    short num1, num2, sum;

    width = (short)10; // 명시적 형변환 -> casting operator
    height = 5;
    area = 100.0f;

    // 암묵적 형변환, 자동 형변환
    total = area + width * height;
    printf("Total is %lf.\n", total);

    length = 3.14;
    printf("length is %d.\n", length);

    length = (int)3.14;
    printf("length is %d.\n", length);

    num1 = (short)10;
    num2 = (short)20;
    printf("sizeof(num1 + num2) is %d\n", sizeof(num1 + num2));
    printf("sizeof(\'a\' - \'A\') is %d\n", sizeof('a' - 'A'));

    sum = num1 + num2;
    printf("sum is %d\n", sum);
    printf("sizeof(sum) is %d\n", sizeof(sum));

    return 0;
}