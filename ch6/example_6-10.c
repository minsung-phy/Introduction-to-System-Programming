#include <stdio.h>

int main () {
    int ch;
    printf("Enter a character.\n");
    scanf("%c", &ch);
    if (ch == 'y')
        printf("yes.\n");
    else    
        printf("no.\n");
    
    return 0;
}