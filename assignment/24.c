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
        int ppid = getppid();
        printf("parent process id is %d and ",ppid);
        printf("child process id is %d ",getpid());
        
        sleep(5);

        int ppid1 = getppid();
        printf("\n New parent process id is %d and ",ppid1);
        printf("child process id is %d \n",getpid());



    }
    else{
        printf("Wait for 5 sec,parent died and child will be orphaned hence will go to grandparent");
         exit(i);
    }

return 0;
}