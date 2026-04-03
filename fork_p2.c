#include<stdio.h>
#include<unistd.h>

int main(){
    int parentPID=0;
    int child1PID=0;
    int child2PID=0;
    int id=0;
    parentPID=getpid();
    child1PID=id=fork();

    if(child1PID!=0) child2PID=fork();

    if(child1PID&&child2PID){
        printf("I’m parent! PID differences are %d and %d \n",child1PID-parentPID,child2PID-parentPID);
    }
    sleep(1);
    if(!child1PID&&child2PID){
        printf("I’m child! My PID is %d \n",getpid());
    } 
    sleep(1);
    if(!child2PID){
        printf("I’m child! My PID is %d \n",getpid());
    }
    return 0;
}