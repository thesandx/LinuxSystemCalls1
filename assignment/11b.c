//#include <unistd.h>

      // int symlink(const char *target, const char *linkpath);

#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){

    

   int file_desc = open("dummy.txt",O_WRONLY | O_APPEND); 
      

    dup2(file_desc, 1) ;  
          //since 1 is fd of stdin hence whatever written in fd will be appended in text.
    printf("\nappend text using dup2\n");
      
return 0; 

}












