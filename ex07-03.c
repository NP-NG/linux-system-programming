#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int gNum; 
int main(){
 
     pid_t fpid;
     fpid = fork();
 
     if(fpid > 0){
         while(1){
             printf("Parent_forkpid(%4d) : getpid(%4d), getppid(%4d), um(%d)    \n",(int)fpid, (int)getpid(), (int)getppid(), gNum);
             sleep(5);
             gNum++;
	 }
     }
}
