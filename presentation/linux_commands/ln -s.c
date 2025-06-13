#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 4 || strcmp(argv[1], "-s") != 0) {
        fprintf(stderr, "사용법: %s -s 대상파일 링크파일\n", argv[0]);
        return 1;
    }

    const char *target = argv[2];
    const char *linkname = argv[3];

    if (symlink(target, linkname) == -1) {
        perror("심볼릭 링크 생성 실패");
        return 1;
    }

    printf("심볼릭 링크 생성됨: %s → %s\n", linkname, target);
    return 0;
}
