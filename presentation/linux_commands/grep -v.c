#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc != 3 || strcmp(argv[1], "-v") != 0) {
        fprintf(stderr, "사용법: %s -v 검색어 파일이름\n", argv[0]);
        return 1;
    }

    const char *pattern = argv[2];
    const char *filename = argv[3];

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    char line[MAX_LINE];
    while (fgets(line, sizeof(line), fp)) {
        if (!strstr(line, pattern)) {
            fputs(line, stdout);  // 패턴이 없는 줄만 출력
        }
    }

    fclose(fp);
    return 0;
}
