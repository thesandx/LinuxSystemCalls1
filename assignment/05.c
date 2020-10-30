#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc,char const *argv[]){
int file = 0;

    while(1){

       

        if(file<6){
          //create file
          //char  dummy[100]= "dummy";
       // strcpy(dummy, (char)file);
          //strcpy(dummy, ".txt");
          const char *name = "dummy.txt";
          int fd1 = open(name,O_CREAT|O_WRONLY|O_TRUNC,0644);
	      char buffer_start[] = "Test message \n Hello world";
	      write(fd1,buffer_start,sizeof(buffer_start));
	      close(fd1);
          printf("%d file created",file);
          file = file+1;
        }

    }
	return 0;


}

