

#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){

    char *buffer,*buffer1;
    size_t bufsize = 100;
    size_t characters;

     buffer = (char *)malloc(bufsize * sizeof(char));
    buffer1 = (char *)malloc(bufsize * sizeof(char));

	int fd1 = open("dummy.txt",O_RDWR | O_APPEND,0666);

    int newdf = dup(fd1);

    char buffer_start[] = " \n append text using dup\n";
   
	write(newdf,buffer_start,sizeof(buffer_start));

    close(fd1);


	return 0;


}

