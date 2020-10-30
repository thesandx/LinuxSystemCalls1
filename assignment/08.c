

#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){
       char *buffer;
    size_t bufsize = 32;
    size_t characters;

    buffer = (char *)malloc(bufsize * sizeof(char));

	int fd1 = open("./dummy.txt",O_RDWR,0666);
     printf("%d",fd1);
    int bytes = read(fd1,buffer,bufsize);
    //printf("%d",bytes);

     printf("%s",buffer);

     free(buffer);
	
	return 0;


}

