
#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){

    

   int file_desc = open("dummy.txt",O_WRONLY | O_APPEND); 
      

    int file_desc1 =fcntl(file_desc, F_DUPFD, 0);

    char buffer_start[] = " \n append text using fcntl\n";
	write(file_desc1,buffer_start,sizeof(buffer_start));

    close(file_desc);
    close(file_desc1);

      
return 0; 

}
