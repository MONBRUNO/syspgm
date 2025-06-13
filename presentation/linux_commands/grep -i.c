#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024

// 소문자로 변환된 문자열 복사
void to_lowercase(char *dest, const char *src) {
    for (int i = 0; src[i]; i++) {
        dest[i] = tolower((unsigned char)src[i]);
    }
    dest[strlen(src)] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 4 || strcmp(argv[1], "-i") != 0) {
        fprintf(stderr, "사용법: %s -i 검색어 파일이름\n", argv[0]);
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
    char lowered_line[MAX_LINE];
    char lowered_pattern[256];

    to_lowercase(lowered_pattern, pattern);

    while (fgets(line, sizeof(line), fp)) {
        to_lowercase(lowered_line, line);
        if (strstr(lowered_line, lowered_pattern)) {
            fputs(line, stdout);  // 원래 줄 출력
        }
    }

    fclose(fp);
    return 0;
}
