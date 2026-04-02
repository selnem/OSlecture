#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
    int pid;
    int id = 0;
    pid = fork();
    printf("pid =%d",pid);
    if (pid == 0) {
        id=id+2;
        pid = fork();
    } else {
        id++;
    }
    if (pid == 0) id++;
    else {
        pid = fork();
        if( pid == 0 ) id++;
    }
    printf("%d\n", id);
    fflush(stdout);
    sleep(1);
    return 0;
}
