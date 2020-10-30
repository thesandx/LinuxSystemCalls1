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

	int fd1 = open("dummy.txt",O_RDWR,0644);
    //now read it
    int sizebuf = read(fd1, buffer,bufsize);

    //printf("%d",sizebuf);


//create new file
    const char pathname[] = "dummy7Create.txt" ;
    int fdnew = open(pathname,O_RDWR, 0666);

    //now write in to it

    write(fdnew,buffer,bufsize);
	return 0;


}

