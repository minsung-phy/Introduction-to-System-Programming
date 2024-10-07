#include <stdio.h>

int main () {
    int one, two, three;

    one = 1;
    // three = two + 1; // 오류
    // two = one + 1; // 오류
    // printf("one : %d, two : %d, three : %d.\n", one, two, three);

    one = 1;
    two = one + 1;
    three = two + 1;
    printf("one : %d, two : %d, three : %d.\n", one, two, three);
    
    return 0;
}