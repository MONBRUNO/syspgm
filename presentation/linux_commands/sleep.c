#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: %s 초\n", argv[0]);
        return 1;
    }

    int seconds = atoi(argv[1]);

    if (seconds < 0) {
        fprintf(stderr, "음수는 허용되지 않습니다.\n");
        return 1;
    }

    printf("%d초 동안 대기 중...\n", seconds);
    sleep(seconds);
    printf("종료!\n");

    return 0;
}
