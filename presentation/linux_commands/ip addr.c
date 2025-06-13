#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>

int main() {
    int fd;
    struct ifconf ifc;
    struct ifreq ifr[10];  // 최대 10개 인터페이스만 처리
    char ip[INET_ADDRSTRLEN];

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0) {
        perror("socket");
        return 1;
    }

    ifc.ifc_len = sizeof(ifr);
    ifc.ifc_req = ifr;

    if (ioctl(fd, SIOCGIFCONF, &ifc) == -1) {
        perror("ioctl SIOCGIFCONF");
        close(fd);
        return 1;
    }

    int count = ifc.ifc_len / sizeof(struct ifreq);
    for (int i = 0; i < count; i++) {
        struct ifreq *item = &ifr[i];

        // IP 주소 얻기
        struct sockaddr_in *addr = (struct sockaddr_in *)&item->ifr_addr;
        inet_ntop(AF_INET, &addr->sin_addr, ip, sizeof(ip));

        printf("%s: %s\n", item->ifr_name, ip);
    }

    close(fd);
    return 0;
}
