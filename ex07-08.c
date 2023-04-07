#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void func1();
void func2();

int main() {
    printf("hello!\n");
    atexit(func1);
    atexit(func2);

    printf("bye!\n");
    exit(0);
}

void func1() {
    printf("func1\n");
}

void func2() {
    printf("func2\n");
}
