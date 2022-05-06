#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <mqueue.h>

void* Send(void *param){
   mqd_t mq1 = mq_open("/mq1", O_WRONLY);
    char str[64];

    while (1)
    {
        fgets(str, sizeof(str), stdin);
        if(str[strlen(str) - 1 ] == '\n') str[strlen(str) - 1 ] = 0;
        mq_send(mq1, str, strlen(str) + 1, 0);
        if (strncmp(str, "exit", strlen("exit")) == 0)
        {
            break;
        }
    }

    mq_close(mq1);
    exit(EXIT_FAILURE);
    return NULL;
}


int main(int argc, char *argv[]){
    pthread_t threadID;
    pthread_create(&threadID,NULL,&Send,NULL);
     mqd_t mq;

    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 32;
    attr.mq_curmsgs = 0;

    mq = mq_open("/mq0", O_RDONLY | O_CREAT, 0644, &attr);
    char buff[32];

    while (1)
    {
        mq_receive(mq, buff, 32, NULL);
        printf("Message received: %s\n", buff);
        if( strncmp(buff, "exit", strlen("exit")) == 0){
            break;
        }
    }

    mq_close(mq);
    mq_unlink("/mq0");
    exit(EXIT_SUCCESS);
}