
#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){
    struct stat sb;
    size_t bufsize = 32;
    size_t characters;

 

	//int fd1 = open("dummy1.txt",O_CREAT|O_WRONLY|O_TRUNC,0644);
	
    int statsnum = stat("dummy1.txt",&sb);

    printf("I-node number:            %ld\n", (long) sb.st_ino);
     printf("Number of hard links:            %ld\n", (long) sb.st_nlink);
      printf("UID:            %ld\n", (long) sb.st_uid);
       printf("GID:            %ld\n", (long) sb.st_gid);
        printf("SIZE:            %ld\n", (long) sb.st_size);
         printf("Block size:            %ld\n", (long) sb.st_blksize);
          printf("Number of block size:            %ld\n", (long) sb.st_blocks);
           printf("Time of last access:            %ld\n", (long) sb.st_atime);
            printf("Time of last modified:            %ld\n", (long) sb.st_mtime);
             printf("Time of last change:            %ld\n", (long) sb.st_ctime);
    





	return 0;


}

