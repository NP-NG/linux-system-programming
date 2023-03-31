#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int filecount;
int dirCount;
int isDir(char *name);

int main() {

    DIR *dirp;
    struct dirent *dentry;
    if((dirp=opendir(".")) == NULL) {
        exit(1);
    }

    while (dentry = readdir(dirp)) {
        if (dentry->d_ino != 0) {
		if(isDir(dentry->d_name)) {
			dirCount++;
		} else {
			filecount++;
		}
        }
    }
    printf("file : %d\n dir : %d\n", filecount, dirCount);

    closedir(dirp);
}

int isDir(char *name) {
    DIR *dirp;
    dirp = opendir(name);
    closedir(dirp);
    return dirp == NULL ? 0 : 1;
}
