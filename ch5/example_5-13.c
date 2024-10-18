#include <stdio.h>

void comment(char);

int main () {
    char grade;
    printf("Enter your grade in capital letter. __\b\b");
    scanf("%c", &grade);
    comment(grade);

    return 0;
}

void comment (char ch) {
    switch (ch) {
        case 'A' :
            printf("Excellent.\n");
            break;
        case 'B' :
            printf("Good.\n");
            break;
        case 'C' :
            printf("Not bad.\n");
            break;
        case ('C' + 1) :
            printf("Need effort.\n");
            break;
        case 'F' :
            printf("Yon can do better than this.\n");
            break;
        default :
            printf("No such grade.\n");
            break;
    }
    return;
}