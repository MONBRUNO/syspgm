#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: %s 디렉터리이름\n", argv[0]);
        return 1;
    }

    const char *dirname = argv[1];

    if (rmdir(dirname) == -1) {
        perror("rmdir");
        return 1;
    }

    printf("디렉터리 삭제됨: %s\n", dirname);
    return 0;
}
