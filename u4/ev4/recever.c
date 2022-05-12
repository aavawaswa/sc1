#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <mqueue.h>

char text[21][100];

void *Send(void *param)
{
    mqd_t mq1 = mq_open("/mq1", O_WRONLY);
    char str[64];

    while (1)
    {
        fgets(str, sizeof(str), stdin);
        if (str[strlen(str) - 1] == '\n')
            str[strlen(str) - 1] = 0;
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

int main(int argc, char *argv[])
{
    pthread_t threadID;
    pthread_create(&threadID, NULL, &Send, NULL);
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
        if (strncmp(buff, "exit", strlen("exit")) == 0)
        {
            break;
        }
        if (strncmp(buff, "./FileIn2", strlen("./FileIn2")) == 0)
        {

            FILE *inFile = fopen("./FileIn2", "r");

            char buffer[64];
            char *status = NULL;

            do
            {
                status = fgets(buffer, sizeof(buffer), inFile);
                if (status != NULL)
                {
                    printf("%s", buffer);
                }
            } while (status != NULL);
            printf("\n");

            fclose(inFile);
        }
        if (strncmp(buff, "./FileIn2inv", strlen("./FileIn2inv")) == 0)
        {
         
          
            int MAXIMA_LONGITUD_CADENA = 500; //caracteres por renglon
            int CANTIDAD_LINEAS = 1364; //cantidad de renglones

            char palabras[CANTIDAD_LINEAS][MAXIMA_LONGITUD_CADENA];

            char buferArchivo[MAXIMA_LONGITUD_CADENA];

            FILE *archivo = fopen("FileIn2", "r");

            int indice = 0;

            while (fgets(buferArchivo, MAXIMA_LONGITUD_CADENA, archivo))
            {
                strtok(buferArchivo, "\n");
                memcpy(palabras[indice], buferArchivo, MAXIMA_LONGITUD_CADENA);
                indice++;
            }
            fclose(archivo);
            int i;
            for (i = CANTIDAD_LINEAS; i >= 0; i--)
            {
                printf("'%s\n", palabras[i]);
            }
          
        }
    }

    mq_close(mq);
    mq_unlink("/mq0");
    exit(EXIT_SUCCESS);
}