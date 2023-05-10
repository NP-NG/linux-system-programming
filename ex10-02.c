#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main() {

	sigset_t set;
	int result;

	sigemptyset(&set);
	result = sigismember(&set, SIGALRM);
	printf("sigalrm is %s a member\n", result ? "" : "not");
	sigaddset(&set, SIGALRM);
	result = sigismember(&set, SIGALRM);
	printf("sigalrm is %s a member\n", result ? "" : "not");
	sigfillset(&set);
	result = sigismember(&set, SIGCHLD);
        printf("sigchld is %s a member\n", result ? "" : "not");
	sigaddset(&set, SIGCHLD);
        result = sigismember(&set, SIGCHLD);
        printf("sigchld is %s a member\n", result ? "" : "not");

}
