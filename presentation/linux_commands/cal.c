#include <stdio.h>
#include <time.h>

int get_days_in_month(int year, int month) {
    static const int days_in_month[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (month == 2) {
        // 윤년 체크
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return 29;
    }
    return days_in_month[month - 1];
}

void print_calendar(int year, int month) {
    struct tm first_day = {
        .tm_year = year - 1900,
        .tm_mon = month - 1,
        .tm_mday = 1
    };
    mktime(&first_day);  // 요일 계산

    int start_day = first_day.tm_wday; // 0: Sunday
    int days = get_days_in_month(year, month);

    printf("     %d년 %d월\n", year, month);
    printf("Su Mo Tu We Th Fr Sa\n");

    // 시작 요일 앞 공백 출력
    for (int i = 0; i < start_day; ++i) {
        printf("   ");
    }

    // 날짜 출력
    for (int day = 1; day <= days; ++day) {
        printf("%2d ", day);
        if ((start_day + day) % 7 == 0)
            printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    time_t now = time(NULL);
    struct tm *local = localtime(&now);

    int year = local->tm_year + 1900;
    int month = local->tm_mon + 1;

    if (argc == 3) {
        year = atoi(argv[1]);
        month = atoi(argv[2]);
        if (month < 1 || month > 12) {
            fprintf(stderr, "1~12월 사이의 숫자를 입력하세요.\n");
            return 1;
        }
    } else if (argc != 1) {
        fprintf(stderr, "사용법: %s [연도 월]\n", argv[0]);
        return 1;
    }

    print_calendar(year, month);
    return 0;
}
