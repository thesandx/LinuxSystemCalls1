#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include<sched.h>

int main(int argc,char const *argv[]){

int pid = getppid();

printf("process id is: %d\n",pid);

int i = sched_getscheduler(pid);
switch (i){
    case SCHED_OTHER : printf("current sched policy is : OTHER\n"); break;
    case SCHED_RR : printf("current sched policy is : RR\n"); break;
    case SCHED_FIFO : printf("current sched policy is : FIFO\n"); break;

}


struct sched_param param;
   

   param.sched_priority = 50;
   int k = sched_setscheduler(pid, SCHED_FIFO, &param);

   if(k==-1){
       perror("Error:");
       exit(pid);
   }

   printf("%d\n",k);


int j = sched_getscheduler(pid);
switch (j){
    case SCHED_OTHER : printf("current sched policy is : OTHER\n"); break;
    case SCHED_RR : printf("current sched policy is : RR\n"); break;
    case SCHED_FIFO : printf("current sched policy is : FIFO\n"); break;

}










    

return 0;
}