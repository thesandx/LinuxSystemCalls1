
#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){

    

   int file_desc = open("dummy.txt",O_RDWR); 
      

    int mode  =fcntl(file_desc, F_GETFL);

//source for int to read write converter used below.
//https://stackoverflow.com/questions/61909358/how-to-get-the-mode-of-a-file-descriptor/61932636#61932636

  if(mode==32768){
    printf("mode of file is %d i.e read mode \n",mode);
  }

  if(mode==32769){
    printf("mode of file is %d i.e write mode \n",mode);
  }

  if(mode==32770){
    printf("mode of file is %d i.e read  and write mode \n",mode);
  }
    

   
    close(file_desc);
    

      
return 0; 

}
