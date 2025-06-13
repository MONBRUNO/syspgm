#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <pwd.h>
#include <sys/sysinfo.h>

void print_sysinfo() {
    struct sysinfo info;
    if (sysinfo(&info) == -1) {
        perror("sysinfo");
        return;
    }

    printf("Uptime: %ld sec | Load average: %.2f, %.2f, %.2f\n",
           info.uptime,
           info.loads[0] / 65536.0,
           info.loads[1] / 65536.0,
           info.loads[2] / 65536.0);
    printf("Memory: Total: %ld MB, Free: %ld MB\n",
           info.totalram / (1024 * 1024),
           info.freeram / (1024 * 1024));
    printf("----------------------------------------------------------------\n");
}

void print_process_summary(int limit) {
    DIR *dir = opendir("/proc");
    struct dirent *entry;
    int count = 0;

    printf("%-6s %-10s %-5s %s\n", "PID", "USER", "STATE", "CMD");

    while ((entry = readdir(dir)) != NULL && count < limit) {
        if (!isdigit(entry->d_name[0])) continue;

        char path[256], state, cmd[256] = "";
        int uid = -1, pid = atoi(entry->d_name);

        // /proc/[pid]/status → UID, State
        snprintf(path, sizeof(path), "/proc/%d/status", pid);
        FILE *fp = fopen(path, "r");
        if (!fp) continue;

        char line[256];
        while (fgets(line, sizeof(line), fp)) {
            if (strncmp(line, "Uid:", 4) == 0) {
                sscanf(line, "Uid:\t%d", &uid);
            }
            if (strncmp(line, "State:", 6) == 0) {
                sscanf(line, "State:\t%c", &state);
            }
        }
        fclose(fp);

        // /proc/[pid]/cmdline → Command
        snprintf(path, sizeof(path), "/proc/%d/cmdline", pid);
        fp = fopen(path, "r");
        if (fp) {
            fgets(cmd, sizeof(cmd), fp);
            fclose(fp);
        }

        // UID → username
        struct passwd *pw = getpwuid(uid);
        const char *user = pw ? pw->pw_name : "unknown";

        printf("%-6d %-10s %-5c %s\n", pid, user, state, cmd[0] ? cmd : "(no cmd)");
        count++;
    }

    closedir(dir);
}

int main() {
    print_sysinfo();
    print_process_summary(5);  // 상위 5개 프로세스만 예시 출력
    return 0;
}
