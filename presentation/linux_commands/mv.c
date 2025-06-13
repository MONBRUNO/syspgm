#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "사용법: %s 원본파일 대상파일\n", argv[0]);
        return 1;
    }

    const char *src = argv[1];
    const char *dst = argv[2];

    if (rename(src, dst) == -1) {
        perror("이동(또는 이름 변경) 실패");
        return 1;
    }

    printf("이동 또는 이름 변경 완료: %s → %s\n", src, dst);
    return 0;
}
