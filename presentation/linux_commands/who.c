#include <stdio.h>
#include <utmp.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    struct utmp entry;
    FILE *fp = fopen(_PATH_UTMP, "rb");  // 로그인 기록 파일

    if (!fp) {
        perror("fopen");
        return 1;
    }

    while (fread(&entry, sizeof(entry), 1, fp) == 1) {
        // USER_PROCESS: 로그인된 사용자
        if (entry.ut_type == USER_PROCESS) {
            char timebuf[64];
            time_t t = entry.ut_time;
            struct tm *tm_info = localtime(&t);
            strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M", tm_info);

            printf("%s\t%s\t%s\n",
                   entry.ut_user,
                   entry.ut_line,
                   timebuf);
        }
    }

    fclose(fp);
    return 0;
}
