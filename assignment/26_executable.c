#include<stdio.h>

int main(int argc,char const *argv[],char *envp[]){
    if(argc!=2){
    printf("hello world\n");
    }else{
        printf("hello %s\n",argv[1]);
    }
    
}