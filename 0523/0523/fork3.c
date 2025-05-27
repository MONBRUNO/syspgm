#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() 
{
    int pid1, pid2;

    pid1 = fork();
    if (pid1 == 0) {
        // 자식 1
        printf("[Child 1] : Hello, world! pid=%d\n", getpid());
        exit(0);
    }

    pid2 = fork();
    if (pid2 == 0) {
        // 자식 2
        printf("[Child 2] : Hello, world! pid=%d\n", getpid());
        exit(0);
    }

    // 부모 프로세스
    printf("[Parent] : Hello, world! pid=%d\n", getpid());

    return 0;
}
