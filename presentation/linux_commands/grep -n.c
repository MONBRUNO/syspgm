#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc != 4 || strcmp(argv[1], "-n") != 0) {
        fprintf(stderr, "사용법: %s -n 검색어 파일이름\n", argv[0]);
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
    int line_num = 1;

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, pattern)) {
            printf("%d:%s", line_num, line);
        }
        line_num++;
    }

    fclose(fp);
    return 0;
}
