#include <stdio.h>
#include <unistd.h>

int main() {
    char *username = getlogin();

    if (username) {
        printf("%s\n", username);
    } else {
        perror("getlogin");
        return 1;
    }

    return 0;
}
