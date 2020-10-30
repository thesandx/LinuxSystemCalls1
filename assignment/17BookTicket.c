
#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include "17ticketStruct.c"


//note gcc fileName.c -lm to compile this file

int main(int argc,char const *argv[]){

    int fd;
    struct ticket db,temp_db;

	struct flock lock,savelock;

	fd = open("ticket_db",O_RDWR,0666);

   int r = read(fd, &db,sizeof(db));
   printf("old ticket number is :- %d\n",db.ticket_number);

     

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
      printf("Locking file\n");
       lock.l_type    = F_WRLCK; 
      fcntl(fd, F_SETLKW, &savelock);
      printf("file Locked\n");

   

      

      temp_db.ticket_number = db.ticket_number+1;

       printf("new ticket number is :- %d\n",temp_db.ticket_number);


        int w = write(fd,&temp_db,sizeof(db));

       // printf("%d\n",w);

        if(w==-1){
           perror("Error:");
        }

       


     savelock.l_type = F_UNLCK;
    printf("UnLocking file\n");
     fcntl(fd, F_SETLK, &savelock);
     printf("file UnLocked\n");
      close(fd);

}
	return 0;


}

