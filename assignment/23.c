#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/wait.h>






int main(int argc,char const *argv[]){

    int i = fork();
    if(i==0){
        printf("child process id is %d \n",getpid());
        exit(0);
    }
    else{
        printf("Now parent is sleeping for 10 sec,and child will be roaming around to find me as Zombie ;)");
        printf("parent process id is %d \n",getpid());
         
         sleep(10);
    }
    printf("Now parent wakeup and child found me.He was so worried ;)\n");
    wait(0);

return 0;
}