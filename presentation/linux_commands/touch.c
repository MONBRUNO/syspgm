#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <utime.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: %s 파일이름\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    struct stat st;

    // 파일이 없으면 생성
    if (access(filename, F_OK) == -1) {
        int fd = open(filename, O_CREAT | O_WRONLY, 0644);
        if (fd == -1) {
            perror("파일 생성 실패");
            return 1;
        }
        close(fd);
        printf("파일 생성됨: %s\n", filename);
    } else {
        // 존재하면 수정 시간 갱신
        if (utime(filename, NULL) == -1) {
            perror("시간 갱신 실패");
            return 1;
        }
        printf("파일 존재 → 시간 갱신됨: %s\n", filename);
    }

    return 0;
}
