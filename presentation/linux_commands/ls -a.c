#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    const char *path = ".";
    int show_all = 0;

    // 옵션 파싱
    if (argc >= 2) {
        if (strcmp(argv[1], "-a") == 0) {
            show_all = 1;
            if (argc == 3) path = argv[2];  // 예: ls -a /etc
        } else {
            path = argv[1];  // 예: ls /etc
        }
    }

    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (!show_all && entry->d_name[0] == '.')
            continue;  // 숨김 파일 생략

        printf("%s  ", entry->d_name);
    }

    printf("\n");
    closedir(dir);
    return 0;
}
