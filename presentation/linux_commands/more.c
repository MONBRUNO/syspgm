#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PAGE_LINES 20   // 한 페이지에 출력할 줄 수

void pause_screen() {
    printf("-- 더 보려면 Enter, 종료하려면 q 입력 -- ");
    int ch = getchar();
    if (ch == 'q' || ch == 'Q') {
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: %s 파일이름\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("파일 열기 실패");
        return 1;
    }

    char line[1024];
    int line_count = 0;

    while (fgets(line, sizeof(line), fp)) {
        fputs(line, stdout);
        line_count++;

        if (line_count == PAGE_LINES) {
            pause_screen();
            line_count = 0;
        }
    }

    fclose(fp);
    return 0;
}
