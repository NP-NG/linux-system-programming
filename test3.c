
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void final();

int fd;

int main() {

    ssize_t nread;
    char buff[1024];
    fd = open("a.txt", O_CREAT|O_WRONLY|O_TRUNC);
    atexit(final);
    
    while((nread = read(fd, buff, 1024)) > 0) {
        printf("%s", buff);
    }
}

void final() {
    printf("close fd\n");
    close(fd);
}
