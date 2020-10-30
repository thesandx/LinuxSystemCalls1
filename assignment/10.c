//#include <unistd.h>

      // int symlink(const char *target, const char *linkpath);

#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){

    char *buffer;
    size_t bufsize = 10;
    size_t characters;

     buffer = (char *)malloc(bufsize * sizeof(char));

	int fd1 = open("dummy.txt",O_RDWR);
   // int sizebuf = read(fd1, buffer,bufsize);

    //write 10 bytes

    int wr = write(fd1,"hello",bufsize);

    printf("wrote 10 bytes\n");

    int lsk = lseek(fd1,10,SEEK_SET);

    printf("moved pointer by %d\n",lsk);

    int wr1 = write(fd1,"world",bufsize);
printf("Again wrote 10 bytes");






	
	
	return 0;


}

