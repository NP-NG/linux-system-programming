#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    DIR *dirp;
    struct dirent *dentry;

    if ((dirp = opendir("./udw")) == NULL) {
        printf("실패\n");
    } else {
        printf("상공\n");
    }
}
