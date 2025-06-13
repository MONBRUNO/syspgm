#include <stdio.h>
#include <unistd.h>

int main() {
    if (chdir("..") != 0) {
        perror("chdir");
        return 1;
    }

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("현재 디렉터리: %s\n", cwd);
    } else {
        perror("getcwd");
        return 1;
    }

    return 0;
}
