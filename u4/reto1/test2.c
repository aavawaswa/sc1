#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *inFile = fopen("./FileIn2","r");

    char buffer[64];
    char *status =  NULL;

    do{
        status = fgets(buffer, sizeof(buffer),inFile);
        if(status != NULL){
            printf("%s",buffer);
        }
    }while (status !=NULL);
    printf("\n");

    fclose(inFile);

    return(EXIT_SUCCESS);
}