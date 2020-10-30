
#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include "17ticketStruct.c"


//note gcc recordName.c -lm to compile this record

int main(int argc,char const *argv[]){

    int fd;
    int recordnum;
    struct ticket db,temp_db;

	struct flock lock,savelock;

printf("Enter record number (between 1-3)\n");
    scanf("%d",&recordnum);

	fd = open("dummy18.txt",O_RDWR,0666);


     

  lock.l_type    = F_WRLCK; 
  lock.l_start   = 15*recordnum;
  lock.l_whence  = SEEK_CUR;
  lock.l_len     = 15;      
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
      printf("Locking record \n");
       lock.l_type    = F_WRLCK; 
      fcntl(fd, F_SETLKW, &savelock);
      printf("record Locked\n");

   

      

     char buffer[] = "new text";

     printf("data going to written is - %s\n",buffer);


        int w = write(fd,buffer,sizeof(buffer));

       // printf("%d\n",w);

        if(w==-1){
           perror("Error:");
        }

       


     savelock.l_type = F_UNLCK;
    printf("UnLocking record\n");
     fcntl(fd, F_SETLK, &savelock);
     printf("record UnLocked\n");
      close(fd);

}
	return 0;


}

