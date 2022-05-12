#include <stdio.h>
#include <string.h>



int main()
{
  int MAXIMA_LONGITUD_CADENA = 500;
  int CANTIDAD_LINEAS = 1364;

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
        printf("'%s'\n", palabras[i]);
    }
    return 0;
}