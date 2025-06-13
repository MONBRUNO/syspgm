#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "사용법: %s 모드(8진수) 파일이름\n", argv[0]);
        return 1;
    }

    const char *mode_str = argv[1];
    const char *filename = argv[2];

    // 8진수로 변환
    mode_t mode = strtol(mode_str, NULL, 8);

    if (chmod(filename, mode) == -1) {
        perror("chmod 실패");
        return 1;
    }

    printf("권한 변경 완료: %s → %s\n", filename, mode_str);
    return 0;
}
