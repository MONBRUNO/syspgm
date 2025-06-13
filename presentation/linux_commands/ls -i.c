#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    const char *path = ".";

    if (argc == 2) {
        path = argv[1];  // 디렉터리 경로 인자
    }

    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue;  // 숨김 파일 생략

        char filepath[1024];
        snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);

        struct stat st;
        if (stat(filepath, &st) == -1) {
            perror("stat");
            continue;
        }

        printf("%lu %s\n", st.st_ino, entry->d_name);
    }

    closedir(dir);
    return 0;
}
