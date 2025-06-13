#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_LINE 1024

void grep_file(const char *filepath, const char *pattern) {
    FILE *fp = fopen(filepath, "r");
    if (!fp) return;

    char line[MAX_LINE];
    int line_num = 1;

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, pattern)) {
            printf("%s:%d:%s", filepath, line_num, line);
        }
        line_num++;
    }

    fclose(fp);
}

void grep_recursive(const char *path, const char *pattern) {
    struct stat st;
    if (stat(path, &st) == -1) return;

    if (S_ISREG(st.st_mode)) {
        grep_file(path, pattern);
    } else if (S_ISDIR(st.st_mode)) {
        DIR *dir = opendir(path);
        if (!dir) return;

        struct dirent *entry;
        char fullpath[1024];

        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;

            snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
            grep_recursive(fullpath, pattern);
        }

        closedir(dir);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4 || strcmp(argv[1], "-r") != 0) {
        fprintf(stderr, "사용법: %s -r 검색어 디렉터리\n", argv[0]);
        return 1;
    }

    const char *pattern = argv[2];
    const char *target_dir = argv[3];

    grep_recursive(target_dir, pattern);
    return 0;
}
