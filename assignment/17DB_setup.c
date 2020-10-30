
#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "17ticketStruct.c"

int main(int argc,char const *argv[]){

    int fd;
    struct ticket db;
    struct ticket temp_db;

    db.ticket_number = 1;

    fd = open("ticket_db",O_CREAT|O_RDWR|O_TRUNC,0644);

    int w = write(fd,&db,sizeof(db));

    close(fd);
    printf("Ticket number saved successfully.\n");


    //now open and read ticket number
    fd = open("ticket_db",O_RDONLY,0644);

    int r = read(fd,&temp_db,sizeof(db));

    printf("current ticket number is %d\n",temp_db.ticket_number);

    close(fd);









      
return 0; 

}
