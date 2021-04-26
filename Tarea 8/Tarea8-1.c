#include <stdio.h>
#include <stdlib.h>

int main(){
    int* ptr = NULL;
    int* espacio = malloc(64 * 4);
    ptr = espacio;

    espacio[10] = 5000;
    printf("%X\n",espacio);
    /*Nunca sera las misma ya que la computadora cuenta con diferentes procesos, que estan constantemente obteniendo y liberando
    Recursos de la memoria*/
    free(espacio);

    printf("%X",ptr);
    //Imprime la direccion de memoria en espacio, en este caso se imprimira la misma direccion dos veces
}