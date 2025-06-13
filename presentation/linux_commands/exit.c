#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int code = 0;

    if (argc == 2) {
        code = atoi(argv[1]);  // 종료 코드 지정
    }

    printf("프로그램을 종료합니다. (exit code: %d)\n", code);
    exit(code);
}
