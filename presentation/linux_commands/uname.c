#include <stdio.h>
#include <sys/utsname.h>

int main() {
    struct utsname info;

    if (uname(&info) == -1) {
        perror("uname");
        return 1;
    }

    printf("%s\n", info.sysname);  // 커널 이름 출력 (uname 기본 동작)

    return 0;
}
