#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("pause return %d\n", pause());

    return 0;
}
