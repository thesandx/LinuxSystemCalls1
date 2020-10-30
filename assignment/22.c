#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/wait.h>






int main(int argc,char const *argv[]){

    //open the file
    
    int fd = open("dummy22.txt",O_CREAT|O_RDWR|O_TRUNC,0644);

    int i = fork();
    if(i==0){
        char buffer_start[] = "Written by child :- Hello world child\n";
	    write(fd,buffer_start,sizeof(buffer_start));
    }
    else{
         char buffer_start[] = "Written by parent :- Hello world  parent\n";
	     write(fd,buffer_start,sizeof(buffer_start));
    }
    wait(0);
    char buffer1[1024];
    int r = read(fd,buffer1,sizeof(buffer1));
    printf("%s\n",buffer1);
    close(fd);
return 0;
}