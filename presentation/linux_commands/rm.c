#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: %s 파일이름\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];

    if (unlink(filename) == -1) {
        perror("unlink");
        return 1;
    }

    printf("파일 삭제됨: %s\n", filename);
    return 0;
}
