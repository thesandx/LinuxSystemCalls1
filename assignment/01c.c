//#include <unistd.h>

      // int symlink(const char *target, const char *linkpath);

#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){

	const char pathfile[] = "./fifodummy";
	//create fifo file
    int fifo = mkfifo(pathfile, 0744);
    printf("%d",fifo);

	
	return 0;


}

