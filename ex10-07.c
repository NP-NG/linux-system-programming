#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

void timeover(int signum) {
    printf("\n\ntime over!!\n");
    exit(0);
}

int main() {
    char buf[1024];
    char *alpha = "abcdefghijklmnopqrstuvwxyz";

    int timelimit;
    struct sigaction act;

    act.sa_handler = timeover;
    sigaction(SIGALRM, &act, NULL);
    printf("input timelimit (sec)..\n");
    scanf("%d", &timelimit);

    alarm(timelimit);

    printf("STRAT!! \n > ");
    scanf("%s", buf);

    if (buf == alpha) {
        printf("you success!");
    } else {
        printf("you fail");
    }
}
