#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

void print_file_type(mode_t mode) {
    if (S_ISREG(mode)) printf("regular file\n");
    else if (S_ISDIR(mode)) printf("directory\n");
    else if (S_ISLNK(mode)) printf("symbolic link\n");
    else if (S_ISCHR(mode)) printf("character device\n");
    else if (S_ISBLK(mode)) printf("block device\n");
    else if (S_ISFIFO(mode)) printf("FIFO/pipe\n");
    else if (S_ISSOCK(mode)) printf("socket\n");
    else printf("unknown\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: %s 파일이름\n", argv[0]);
        return 1;
    }

    struct stat st;
    if (stat(argv[1], &st) == -1) {
        perror("stat");
        return 1;
    }

    printf("File: %s\n", argv[1]);
    printf("Size: %ld\tBlocks: %ld\tIO Block: %ld\t", st.st_size, st.st_blocks, st.st_blksize);
    print_file_type(st.st_mode);
    printf("Device: %lxh\tInode: %ld\tLinks: %ld\n", st.st_dev, st.st_ino, st.st_nlink);
    printf("Access: %s", ctime(&st.st_atime));
    printf("Modify: %s", ctime(&st.st_mtime));
    printf("Change: %s", ctime(&st.st_ctime));

    return 0;
}
