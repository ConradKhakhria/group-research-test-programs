#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
    int fd = open("filename.txt", O_RDONLY);
    int pid;
    char data[100];

    if ((pid = fork()) == 0) {
        for (int i = 0; i < 99; i++) {
            read(fd, &data[i], 1);
        }

        data[99] = '\x00';

        printf("done!\n");
    }

    close(fd);

    printf("data = %s\n", data);
}
