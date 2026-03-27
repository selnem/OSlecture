#include<stdio.h>

int main(){
    char str[50] = "stracetest.txt";
    FILE *pFile = NULL;
    pFile = fopen( str, "w+" );


    fprintf(pFile,"This is a test code.\n");
    fflush(pFile);
    fclose(pFile);
}