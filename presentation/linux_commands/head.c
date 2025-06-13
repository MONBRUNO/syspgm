#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_LINES 10
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int lines_to_print = DEFAULT_LINES;
    const char *filename;

    if (argc == 2) {
        filename = argv[1];
    } else if (argc == 4 && strcmp(argv[1], "-n") == 0) {
        lines_to_print = atoi(argv[2]);
        filename = argv[3];
    } else {
        fprintf(stderr, "사용법: %s [-n 줄수] 파일이름\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    char line[MAX_LINE];
    int count = 0;
    while (fgets(line, sizeof(line), fp) && count < lines_to_print) {
        fputs(line, stdout);
        count++;
    }

    fclose(fp);
    return 0;
}
