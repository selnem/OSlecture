#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/rtc.h>

int main(){
    char* str = "stracetest.txt";
    FILE *pFile = NULL;
    struct rtc_time tm;
    pFile = fopen( str, "w+" );
    sleep(1);

    int fd = open("/dev/rtc", O_RDONLY);
    if(fd==1){
        fflush(pFile);
        fclose(pFile);
        return 1;
    }
    if (ioctl(fd, RTC_RD_TIME, &tm) == -1) {
        fflush(pFile);
        fclose(pFile);
        close(fd);
        return -1;
    }


    fprintf(pFile,"This is a test code.\n");
    fprintf(pFile,"time: %02d:%02d:%02d.\n",tm.tm_hour, tm.tm_min, tm.tm_sec);
    fflush(pFile);
    fclose(pFile);
}