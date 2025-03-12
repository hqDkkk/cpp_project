#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<errno.h>
int main(){
    pid_t pid = fork();
    if(pid<0){
        perror("pid error");
        return -1;
    }

    if(pid==0){
        std::cout<<"this is a child process"<<std::endl;
    }else{
        std::cout<<"parent process"<<std::endl;
    }


    return 0;
}