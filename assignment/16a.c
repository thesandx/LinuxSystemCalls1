
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

	struct flock lock,savelock;

	int fd = open("dummy.txt",O_RDWR);

  lock.l_type    = F_WRLCK; 
  lock.l_start   = 0;
  lock.l_whence  = SEEK_SET;
  lock.l_len     = 0;        
  savelock = lock;
  fcntl(fd, F_GETLK, &lock);

  if (lock.l_type == F_WRLCK)
  {
     printf("Process %ld has a write lock already!\n",(long) lock.l_pid);
     exit(1);
  }
  else if (lock.l_type == F_RDLCK)
  {
     printf("Process %ld has a read lock already!\n", (long)lock.l_pid);
     exit(1);
  }
  else{
     fcntl(fd, F_SETLK, &savelock);
     pause();
}
	return 0;


}

