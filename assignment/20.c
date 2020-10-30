#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>




int main(int argc,char const *argv[]){

    //Note - if changing to higher priority i.e < 0(default) then you have to login as sudo user using su command.

    int before,after;

    before = nice(0);
    printf("Current priority of program is %d\n",before);

    printf("Changing priority to 10\n");

    after = nice(10);

    if(after==-1){
        perror("Error");
        exit(0);
    }
    else{
        printf("Priority changed\n");
    }

return 0;
}