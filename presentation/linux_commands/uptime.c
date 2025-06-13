#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;

    if (sysinfo(&info) == -1) {
        perror("sysinfo");
        return 1;
    }

    // 현재 시간
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    char time_str[64];
    strftime(time_str, sizeof(time_str), "%H:%M:%S", tm_now);

    // 업타임 계산
    int days = info.uptime / (60 * 60 * 24);
    int hours = (info.uptime / (60 * 60)) % 24;
    int minutes = (info.uptime / 60) % 60;

    // load average
    double load1 = info.loads[0] / 65536.0;
    double load5 = info.loads[1] / 65536.0;
    double load15 = info.loads[2] / 65536.0;

    // 출력
    printf("%s up %d days, %2d:%02d, load average: %.2f, %.2f, %.2f\n",
           time_str, days, hours, minutes, load1, load5, load15);

    return 0;
}
