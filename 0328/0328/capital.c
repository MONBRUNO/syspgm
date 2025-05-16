#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    
    while (1) {
        printf("문자 입력: ");
        scanf(" %c", &ch);
        
        if (ch == '0') {
            break;
        } else if (isupper(ch)) {
            printf("%c의 대문자는 %c 입니다.\n", ch, tolower(ch));
        } else if (islower(ch)) {
            printf("%c의 소문자는 %c 입니다.\n", ch, toupper(ch));
        } else {
            printf("알파벳을 입력하세요.\n");
        }
    }
    
    return 0;
}