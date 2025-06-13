#include <stdio.h>
#include <time.h>

int main() {
    time_t now;
    struct tm *tm_now;

    // 현재 시간 얻기
    time(&now);
    tm_now = localtime(&now);

    // 날짜와 시간 출력
    printf("현재 시간: %04d-%02d-%02d %02d:%02d:%02d\n",
           tm_now->tm_year + 1900,
           tm_now->tm_mon + 1,
           tm_now->tm_mday,
           tm_now->tm_hour,
           tm_now->tm_min,
           tm_now->tm_sec);

    return 0;
}
