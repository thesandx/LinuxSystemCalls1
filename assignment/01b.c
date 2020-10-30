//#include <unistd.h>

      // int symlink(const char *target, const char *linkpath);

#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){

	int fd1 = open("hardummy.txt",O_CREAT|O_WRONLY|O_TRUNC,0644);
	char buffer_start[] = "Test message for hardlink \n Hello world";
	write(fd1,buffer_start,sizeof(buffer_start));
	close(fd1);
	const char oldpath[] = "./hardummy.txt";
	const char newpath[] = "./hard_link_dummy.txt";
	//create hard link
	int hd_link = link(oldpath,newpath);
	return 0;


}

