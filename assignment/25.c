#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/wait.h>






int main(int argc,char const *argv[]){

    int wstatus;

    int firstchild = fork();
    int secondchild = fork();
    int favchild = fork();


   
        waitpid(favchild,&wstatus,WUNTRACED);
         
    

return 0;
}