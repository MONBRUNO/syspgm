#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법: %s 명령어 [인자...]\n", argv[0]);
        return 1;
    }

    if (setuid(0) != 0) {
        perror("setuid 실패 (root 권한 필요)");
        return 1;
    }

    // 명령어 실행
    execvp(argv[1], &argv[1]);

    perror("execvp 실패");
    return 1;
}
