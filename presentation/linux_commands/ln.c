#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "사용법: %s 원본파일 링크파일\n", argv[0]);
        return 1;
    }

    const char *src = argv[1];
    const char *linkname = argv[2];

    if (link(src, linkname) == -1) {
        perror("하드 링크 생성 실패");
        return 1;
    }

    printf("하드 링크 생성됨: %s → %s\n", linkname, src);
    return 0;
}
