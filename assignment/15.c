#include <stdio.h>
//in shell use - printenv | less
 
void main(int argc, char *argv[], char * envp[])
{
    int i;
 
    for (i = 0; envp[i] != NULL; i++)
    {    
        printf("\n%s", envp[i]);
    }
}