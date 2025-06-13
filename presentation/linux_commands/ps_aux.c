#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <pwd.h>
#include <unistd.h>

void print_ps_aux() {
    DIR *dir;
    struct dirent *entry;

    printf("%-10s %5s %10s %s\n", "USER", "PID", "VSZ", "COMMAND");

    dir = opendir("/proc");
    if (!dir) {
        perror("opendir");
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (!isdigit(entry->d_name[0])) continue;

        char path[256];
        FILE *fp;
        int pid = atoi(entry->d_name);
        char cmdline[256] = "(unknown)";
        unsigned long vmsize = 0;
        uid_t uid = -1;
        char user[32] = "unknown";

        // /proc/[pid]/cmdline
        snprintf(path, sizeof(path), "/proc/%d/cmdline", pid);
        fp = fopen(path, "r");
        if (fp) {
            fgets(cmdline, sizeof(cmdline), fp);
            fclose(fp);
        }

        // /proc/[pid]/status
        snprintf(path, sizeof(path), "/proc/%d/status", pid);
        fp = fopen(path, "r");
        if (fp) {
            char line[256];
            while (fgets(line, sizeof(line), fp)) {
                if (sscanf(line, "Uid: %d", &uid) == 1) continue;
                if (sscanf(line, "VmSize: %lu", &vmsize) == 1) continue;
            }
            fclose(fp);
        }

        // UID → 사용자 이름
        struct passwd *pw = getpwuid(uid);
        if (pw) {
            strncpy(user, pw->pw_name, sizeof(user) - 1);
        }

        printf("%-10s %5d %10lu %s\n", user, pid, vmsize, cmdline[0] ? cmdline : "(no cmd)");
    }

    closedir(dir);
}

int main() {
    print_ps_aux();
    return 0;
}
