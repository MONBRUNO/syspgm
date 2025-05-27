#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>      // fork(), getpid()
#include <sys/types.h>   // pid_t
#include <sys/wait.h>    // wait()

int main() 
{
    int pid, child, status;

    printf("[%d] 부모 프로세스 시작\n", getpid());

    pid = fork();

    if (pid == 0) {
        // 자식 프로세스
        printf("[%d] 자식 프로세스 시작\n", getpid());
        exit(1);  // 종료 코드 1로 종료
    }

    // 부모 프로세스
    child = wait(&status);  // 자식 프로세스가 끝날 때까지 기다림

    printf("[%d] 자식 프로세스 %d 종료\n", getpid(), child);
    printf("\t종료 코드 %d\n", status >> 8);  // 자식의 exit code 추출

    return 0;
}
