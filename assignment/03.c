//#include <unistd.h>

      // int symlink(const char *target, const char *linkpath);

#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){

//create file
    const char pathname[] = "./dummy3Create.txt" ;
    int fd = creat(pathname, 0744);

    printf("file descripter value is %d",fd);

	
	return 0;


}

