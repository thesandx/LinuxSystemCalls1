#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/time.h>

static long get_nanos(void) {
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    return (long)ts.tv_sec * 1000000000L + ts.tv_nsec;
}

int main(int argc,char const *argv[]){


    

long start = get_nanos();
   
    int id = getpid();

    long end = get_nanos();

    printf("id of process is  %d \n",id);

     unsigned long diff = end-start;
     printf("Time  taken to calculate is %lu \n",diff);

return 0;
}