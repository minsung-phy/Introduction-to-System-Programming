/*
// example_14-1.c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int ch; 

    FILE * src = fopen("file/from.txt", "rt"); // 읽기 모드로 염
    FILE * dest = fopen("file/to.txt", "wt"); // 쓰기 모드로 염

    if (src == NULL || dest == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // getc() : 키보드에서 들어오는 것을 한 문자를 읽어옴
    // fgetc(src) : src에서 한 문자를 읽어옴
    
    // putc() : 화면에다 한 문자를 출력
    // fputc(ch, dest) : dest에서 ch를 씀

    // EOF : 파일의 끝  

    // feof(src) : src의 끝까지 갔는지 확인

    while ((ch = fgetc(src)) != EOF) // fgetc로 src에서 한 문자를 읽어와서 ch에 대입. 이것이 파일의 끝(EOF)에 도달하지 않았다면 (죽, 정상적으로 읽어왔다면)
        fputc(ch, dest);
    
    if (feof(src))
        printf("Copy complete.\n");
    else
        printf("Error while copying.\n");
    
    fclose(src);
    fclose(dest);

    return 0;
}
*/

/*
// example_14-2.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int ch;
    unsigned int num = 0;

    FILE * fp = fopen("file/from.txt", "rt");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    ch = fgetc(fp);
    while(isdigit(ch)) { 
        // isdigit(ch) : ch가 숫자면 true, 아니면 false
        num = num * 10 + ch - '0'; // ch == 82 (문자 : 2, 0의 아스키 코드 값 : 80) -> 82 - '0' == 82 - 80 == 2
        ch = fgetc(fp);
    }
    printf("Number is %d.\n", num);
    
    fclose(fp);

    return 0;
}
*/

/*
// example_14-3.c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char buff[100];
    FILE * src = fopen("file/from.txt", "rt");
    FILE * dest = fopen("file/to.txt", "wt");

    if (src == NULL || dest == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(buff, sizeof(buff), src) != NULL) // 파일 끝까지 읽었다면 NULL이 나옴
        fputs(buff, dest);
    
    if (feof(src))
        printf("Copy complete.\n");
    else
        printf("Error while copying.\n");

    fclose(src);
    fclose(dest);

    return 0;

    // gets() : buffer에서 string을 읽어옴
    // puts() : string을 화면에 출력
    // fgets() : 파일에서 문자열(string)을 읽어옴 -> \n까지 읽어서 하나의 문자열로 처리함
    // fputs() : 파일에 문자열(string)을 씀
    // char * fgets(char * buff, int max, FILE* fp);
    // : 파일 fp에서 max-1만큼 읽어서 buff에 저장
    // int* fputs(const char* str, FILE* fp);
    // : str을 파일 fp에 씀
}
*/

/*
// fwrite, fread 예제
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
} studentType ;

int main() {
    int i, count;

    studentType stdnt, stdnt2;

    FILE * dest = fopen("file/student.bin", "wb");

    stdnt.id = 2023;
    strcpy(stdnt.name, "James"); // 배열이라 strcpy 사용

    count = fwrite(&stdnt, sizeof(studentType), 1, dest);

    fclose(dest);

    // dest에 작성하였으니, 그것을 읽어와서 stdnt2에 대입해보자

    FILE * src = fopen("file/student.bin", "rb");

    fread(&stdnt2, sizeof(studentType), 1, src);
    printf("%d %s\n", stdnt2.id, stdnt2.name);

    fclose(src);

    return 0;
}
*/

/**/
// fseek 예제
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE * src = fopen("file/alpha.txt", "rt");

    printf("fp : %d\n", ftell(src)); // 현재 파일 포인터 위치 반환 

    fseek(src, -2, SEEK_END);
    printf("SEEK_END에서 -2만큼 이동한 fp : %d\n", ftell(src)); 
    printf("%c\n", fgetc(src));

    fseek(src, -10, SEEK_CUR);
    // 위의 fgetc(src)에서 하나 출력하였으므로 현재 fp : 25
    printf("SEEK_CUR(25)에서 -10만큼 이동한 fp : %d\n", ftell(src)); 
    printf("%c\n", fgetc(src));

    fseek(src, 3, SEEK_SET);
    printf("SEEK_SET에서 3만큼 이동한 fp : %d\n", ftell(src)); 
    printf("%c\n", fgetc(src));

    rewind(src); // 파일 포인터를 처음으로 보냄
    printf("rewind 후 fp : %d\n", ftell(src)); 
    printf("%c\n", fgetc(src));

    fclose(src);

    return 0;
}