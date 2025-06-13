#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *path = "."; // 기본은 현재 디렉터리

    if (argc == 2) {
        path = argv[1];  // 사용자가 디렉터리 지정한 경우
    }

    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // 숨김 파일 제외하고 출력
        if (entry->d_name[0] != '.')
            printf("%s  ", entry->d_name);
    }
    printf("\n");

    closedir(dir);
    return 0;
}
