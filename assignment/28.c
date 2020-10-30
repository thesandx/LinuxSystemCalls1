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


int max = sched_get_priority_max(SCHED_RR);

int min = sched_get_priority_min(SCHED_RR);

printf("maximum priority is -> %d\n",max);
printf("minimum priority is -> %d\n",min);

    

return 0;
}