#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_MAX 256
#define PATH_MAX 512

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: %s 명령어\n", argv[0]);
        exit(1);
    }

    char command[CMD_MAX];
    snprintf(command, sizeof(command), "man %s", argv[1]);

    int status = system(command);
    if (status == -1) {
        perror("system");
        return 1;
    }

    return 0;
}
