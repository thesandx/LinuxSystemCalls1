//#include <unistd.h>

      // int symlink(const char *target, const char *linkpath);

#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){

    char *str=NULL;
    char str1[1000];


    char *buffer;
    size_t bufsize = 32;
    size_t characters;

     buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

     printf( "Enter any value :\n");
    //scanf("%s", str);

     characters = getline(&buffer,&bufsize,stdin);

    const char pathname[] = "dummy4Create.txt" ;
    int fd = open(pathname,O_CREAT|O_RDWR|O_TRUNC ,0644);
    
    write(fd,buffer,bufsize);
    //printf("file descripter value is %d \n",fd);
    close(fd);
    free(buffer);
    //now again open file to read
    
    int fd1 = open(pathname,O_RDWR,0666);
    int sizebuf = read(fd1, buffer,bufsize);
    printf("%s",buffer);
    close(fd1);

	return 0;


}

