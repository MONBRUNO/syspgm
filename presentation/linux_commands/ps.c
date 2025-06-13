#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void print_processes() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");
    if (!dir) {
        perror("opendir");
        return;
    }

    printf("%5s\t%s\n", "PID", "CMD");
    while ((entry = readdir(dir)) != NULL) {
        if (!isdigit(entry->d_name[0])) continue;

        char cmdline_path[256];
        snprintf(cmdline_path, sizeof(cmdline_path), "/proc/%s/cmdline", entry->d_name);

        FILE *fp = fopen(cmdline_path, "r");
        if (fp) {
            char cmd[256];
            if (fgets(cmd, sizeof(cmd), fp)) {
                printf("%5s\t%s\n", entry->d_name, cmd);
            }
            fclose(fp);
        }
    }

    closedir(dir);
}

int main() {
    print_processes();
    return 0;
}
