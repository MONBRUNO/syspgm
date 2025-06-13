#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: %s 파일이름\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    FILE *fp = fopen(filename, "w");

    if (!fp) {
        perror("fopen");
        return 1;
    }

    printf("입력하세요. Ctrl+D (Linux/macOS) 또는 Ctrl+Z (Windows)로 종료:\n");

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        fputs(buffer, fp);
    }

    fclose(fp);
    printf("파일 저장 완료: %s\n", filename);
    return 0;
}
