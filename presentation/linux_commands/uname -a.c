#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>

int main(int argc, char *argv[]) {
    struct utsname info;

    if (uname(&info) == -1) {
        perror("uname");
        return 1;
    }

    if (argc == 1) {
        printf("%s\n", info.sysname);
    } else if (argc == 2 && strcmp(argv[1], "-a") == 0) {
        printf("%s %s %s %s %s\n",
               info.sysname,   // 커널 이름
               info.nodename,  // 호스트 이름
               info.release,   // 커널 릴리즈
               info.version,   // 커널 버전
               info.machine);  // 머신(아키텍처)
    } else {
        fprintf(stderr, "사용법: %s [-a]\n", argv[0]);
        return 1;
    }

    return 0;
}
