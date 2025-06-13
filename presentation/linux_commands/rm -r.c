#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

int remove_recursive(const char *path) {
    struct stat st;
    
    // 파일 정보 얻기
    if (lstat(path, &st) == -1) {
        perror("lstat");
        return -1;
    }

    // 일반 파일이면 unlink
    if (S_ISREG(st.st_mode) || S_ISLNK(st.st_mode)) {
        if (unlink(path) == -1) {
            perror("unlink");
            return -1;
        }
    }
    // 디렉터리면 내부 파일들 재귀 삭제
    else if (S_ISDIR(st.st_mode)) {
        DIR *dir = opendir(path);
        if (!dir) {
            perror("opendir");
            return -1;
        }

        struct dirent *entry;
        char fullpath[1024];

        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;

            snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
            remove_recursive(fullpath);
        }

        closedir(dir);

        // 디렉터리 비운 후 삭제
        if (rmdir(path) == -1) {
            perror("rmdir");
            return -1;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: %s 디렉터리_또는_파일명\n", argv[0]);
        return 1;
    }

    if (remove_recursive(argv[1]) == 0) {
        printf("삭제 완료: %s\n", argv[1]);
    } else {
        fprintf(stderr, "삭제 실패: %s\n", argv[1]);
    }

    return 0;
}
