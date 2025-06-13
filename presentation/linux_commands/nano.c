#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: %s 파일이름\n", argv[0]);
        return 1;
    }

    char command[256];
    snprintf(command, sizeof(command), "nano %s", argv[1]);

    int result = system(command);
    if (result == -1) {
        perror("system");
        return 1;
    }

    return 0;
}
