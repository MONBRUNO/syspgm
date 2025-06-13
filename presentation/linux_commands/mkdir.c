#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: %s 디렉터리이름\n", argv[0]);
        return 1;
    }

    const char *dirname = argv[1];
    if (mkdir(dirname, 0755) == -1) {
        perror("mkdir");
        return 1;
    }

    printf("디렉터리 생성됨: %s\n", dirname);
    return 0;
}
