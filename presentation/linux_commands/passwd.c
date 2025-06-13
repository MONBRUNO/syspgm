#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

// 입력 숨기기 위한 함수
void disable_echo() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

// 입력 복구
void enable_echo() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

int main() {
    char pass1[128], pass2[128];

    printf("새 비밀번호 입력: ");
    disable_echo();
    fgets(pass1, sizeof(pass1), stdin);
    enable_echo();
    printf("\n");

    printf("비밀번호 재입력: ");
    disable_echo();
    fgets(pass2, sizeof(pass2), stdin);
    enable_echo();
    printf("\n");

    // 줄바꿈 제거
    pass1[strcspn(pass1, "\n")] = '\0';
    pass2[strcspn(pass2, "\n")] = '\0';

    if (strcmp(pass1, pass2) != 0) {
        printf("❌ 비밀번호가 일치하지 않습니다.\n");
        return 1;
    }

    printf("✅ 비밀번호가 설정되었습니다. (파일로 저장)\n");

    // 단순히 텍스트로 저장 (실제로는 절대 이렇게 하면 안 됨)
    FILE *fp = fopen("password.txt", "w");
    fprintf(fp, "%s\n", pass1);
    fclose(fp);

    return 0;
}
