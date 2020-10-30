
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

	int fd1 = open("dummy1.txt",O_CREAT|O_WRONLY|O_TRUNC,0644);
	char buffer_start[] = "Test message \n Hello world";
	write(fd1,buffer_start,sizeof(buffer_start));
	close(fd1);
	const char target[] = "./dummy1.txt";
	const char linkpath[] = "./soft_link_dummy1.txt";
	//create soft link
	int sf_link = symlink(target,linkpath);
	return 0;


}

