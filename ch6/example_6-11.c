#include <stdio.h>

int main () {
    int ch;

    printf("Enter a character.\n");
    for (ch = getchar(); ch != EOF; ch = getchar()) {
        if (ch >= 'a' && ch <= 'z')
            ch -= 'a' - 'A';
        putchar(ch);
        putchar('\n');
        getchar();
        printf("Enter a character.\n");
    }
    return 0;
}
