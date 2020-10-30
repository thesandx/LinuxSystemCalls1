#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/wait.h>

int main(int argc,char const *argv[]){

char *env[] = { "HOME=/usr/home", "LOGNAME=home", (char *)0 };
int execl_return = execle("/bin/ls","ls","-Rl",(char *)NULL,env);
printf("%d\n",execl_return);
    

return 0;
}