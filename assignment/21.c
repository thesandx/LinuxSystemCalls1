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
    }
    else{
         printf("parent process id is %d \n",getpid());
    }
    wait(0);
return 0;
}