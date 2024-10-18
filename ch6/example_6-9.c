#include <stdio.h>

int main () {
    int ch; // EOF를 받아들이려면 정수형으로 선언해야함
    for ( ; ; ) { // 무한 루프 형태
        ch = getchar();
        if (ch == EOF)
            break;
        else 
            putchar(ch);
    }
    return 0;
}