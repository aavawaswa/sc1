#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

char text [21][100];

int main (int argc, char *argv[])
{
    char datos [100][21];

    FILE *FileIn = fopen("./FileIn","r");

    for(int i=99; i>=0; i--)
    {
        fgets((char*)(datos+i),20,FileIn);
    }
    for(int i=0; i<100; i++)
    {
        printf("%d:%s",i,(char*)(datos+i));
    }

}