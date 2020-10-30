#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/wait.h>

int main(int argc,char const *argv[]){

//source-https://tuxthink.blogspot.com/2012/06/using-execl.html?m=0


int execl_return = execl("26_executable","26_executable","sandeep",(char *)NULL);
printf("%d\n",execl_return);
    

return 0;
}