#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    const char *target = ".";  // 기본은 현재 디렉터리

    if (argc == 2) {
        target = argv[1];
    }

    if (chdir(target) != 0) {
        perror("chdir");
        return 1;
    }

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("디렉터리 변경됨: %s\n", cwd);
    } else {
        perror("getcwd");
        return 1;
    }

    return 0;
}
