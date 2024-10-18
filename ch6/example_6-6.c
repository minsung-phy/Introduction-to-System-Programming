#include <stdio.h>

int main() {
    int num;
    while (1) {
        printf("Enter a number to converted.\n");
        scanf("%d", &num);
        if (!(num >= 0))
            break;
        printf("%d is %X in hexadecimal.\n", num, num);
    }

    return 0;
}