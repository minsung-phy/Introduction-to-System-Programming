#include <stdio.h>

int main () {
    int age, count;
    double weight, height;

    printf("Enter age.\n");
    scanf("%d", &age);
    printf("Age : %d.\n", age);
    printf("Enter weight and height.\n");
    scanf("%lf%lf", &weight, &height);
    printf("Weight : %lf, Height : %lf.\n", weight, height);
    printf("Enter weight and height again.\n");
    count = scanf("%lf%lf", &weight, &height);
    printf("scanf returns %d.\n", count);

    return 0;
}