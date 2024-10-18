#include <stdio.h>

int main () {
    int num;

    do {
        printf("Enter a number to be converted.\n");
        scanf("%d", &num);
        printf("%d is %X in hexadecimal.\n", num, num);
    } while (num >= 0);
    return 0;
}