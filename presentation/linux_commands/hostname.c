#include <stdio.h>
#include <unistd.h>

#define HOSTNAME_MAX 256

int main() {
    char hostname[HOSTNAME_MAX];

    // 호스트 이름 얻기
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("%s\n", hostname);
    } else {
        perror("gethostname");
        return 1;
    }

    return 0;
}
