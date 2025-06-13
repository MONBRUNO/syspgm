#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>

void print_file_info(const char *dir, const char *filename) {
    char path[1024];
    snprintf(path, sizeof(path), "%s/%s", dir, filename);

    struct stat st;
    if (stat(path, &st) == -1) {
        perror("stat");
        return;
    }

    // 파일 타입 및 권한
    printf( (S_ISDIR(st.st_mode)) ? "d" : "-");
    printf( (st.st_mode & S_IRUSR) ? "r" : "-");
    printf( (st.st_mode & S_IWUSR) ? "w" : "-");
    printf( (st.st_mode & S_IXUSR) ? "x" : "-");
    printf( (st.st_mode & S_IRGRP) ? "r" : "-");
    printf( (st.st_mode & S_IWGRP) ? "w" : "-");
    printf( (st.st_mode & S_IXGRP) ? "x" : "-");
    printf( (st.st_mode & S_IROTH) ? "r" : "-");
    printf( (st.st_mode & S_IWOTH) ? "w" : "-");
    printf( (st.st_mode & S_IXOTH) ? "x" : "-");

    // 하드링크 수
    printf(" %2ld", st.st_nlink);

    // 사용자, 그룹 이름
    struct passwd *pw = getpwuid(st.st_uid);
    struct group  *gr = getgrgid(st.st_gid);
    printf(" %-8s %-8s", pw ? pw->pw_name : "?", gr ? gr->gr_name : "?");

    // 파일 크기
    printf(" %8ld", st.st_size);

    // 수정 시간
    char timebuf[64];
    strftime(timebuf, sizeof(timebuf), "%b %d %H:%M", localtime(&st.st_mtime));
    printf(" %s", timebuf);

    // 파일 이름
    printf(" %s\n", filename);
}

int main(int argc, char *argv[]) {
    const char *path = ".";

    if (argc == 2) {
        path = argv[1];
    }

    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue;  // 숨김 파일 생략
        print_file_info(path, entry->d_name);
    }

    closedir(dir);
    return 0;
}
