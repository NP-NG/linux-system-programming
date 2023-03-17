#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

void createFile(char* filename, char* alphabet);
char* readFile(char* filename, char* read);
int openFile(char *);
int getAlphabetCount(char* filename);

int main() {
    char filename[1024] = "temp0.txt";
    char fileContent[1024] = "dong dong dong";

    createFile(filename, fileContent);
    int count = getAlphabetCount(filename);
    printf("%d", count);

    return 0;
}

int getAlphabetCount(char* filename) {
    char read[1024] = {};
    readFile(filename, read);

    int count;
    for (int i = 0; i < strlen(read); ++i) {
        if ((read[i] <= 90 && read[i] >= 65) || (read[i] <= 122 && read[i] >= 97)) {
            count++;
        }
    }
    return count;
}

void createFile(char* filename, char* alphabet) {

    int fd = openFile(filename);
    char* a = alphabet;
    write(fd, a, 100);
    close(fd);
}

char* readFile(char* filename, char* ret) {
    
    int fd = openFile(filename);
    read(fd, ret, 100);
}

int openFile(char *filename) {
    return open(filename, O_RDWR | O_CREAT, 0664);
}


