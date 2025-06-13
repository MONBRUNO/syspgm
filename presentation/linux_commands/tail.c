#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024
#define MAX_LINE_LEN 1024
#define DEFAULT_LINES 10

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

    char *lines[MAX_LINES];
    int count = 0;

    char buffer[MAX_LINE_LEN];
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (lines[count % MAX_LINES]) free(lines[count % MAX_LINES]);
        lines[count % MAX_LINES] = strdup(buffer);
        count++;
    }

    int start = (count > lines_to_print) ? count - lines_to_print : 0;
    for (int i = start; i < count; i++) {
        printf("%s", lines[i % MAX_LINES]);
    }

    // 메모리 해제
    for (int i = 0; i < (count < MAX_LINES ? count : MAX_LINES); i++) {
        free(lines[i]);
    }

    fclose(fp);
    return 0;
}
