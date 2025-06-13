#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int pid;
    int sig = SIGTERM;  // 기본 시그널

    if (argc < 2 || argc > 3) {
        fprintf(stderr, "사용법: %s [-시그널번호] PID\n", argv[0]);
        return 1;
    }

    if (argc == 2) {
        pid = atoi(argv[1]);
    } else {
        if (argv[1][0] != '-') {
            fprintf(stderr, "시그널은 -숫자 형식으로 입력하세요 (예: -9)\n");
            return 1;
        }
        sig = atoi(argv[1] + 1);
        pid = atoi(argv[2]);
    }

    if (kill(pid, sig) == -1) {
        perror("kill");
        return 1;
    }

    printf("프로세스 %d에 시그널 %d 전송 성공\n", pid, sig);
    return 0;
}
