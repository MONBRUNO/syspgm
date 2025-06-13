#include <stdio.h>
#include <stdlib.h>

int copy_file(const char *src, const char *dst) {
    FILE *in = fopen(src, "rb");
    if (!in) {
        perror("원본 파일 열기 실패");
        return 1;
    }

    FILE *out = fopen(dst, "wb");
    if (!out) {
        perror("대상 파일 열기 실패");
        fclose(in);
        return 1;
    }

    char buffer[4096];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), in)) > 0) {
        fwrite(buffer, 1, bytes, out);
    }

    fclose(in);
    fclose(out);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "사용법: %s 원본파일 대상파일\n", argv[0]);
        return 1;
    }

    if (copy_file(argv[1], argv[2]) == 0) {
        printf("복사 완료: %s → %s\n", argv[1], argv[2]);
    } else {
        fprintf(stderr, "복사 실패\n");
        return 1;
    }

    return 0;
}
