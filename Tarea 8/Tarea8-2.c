#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 0,sum = 0,i = 0;
    printf("Ingrese la cantidad de numeros a promediar\n ~>");
    scanf("%d",&n);
    int* numeros = (int*) malloc(4 * 64);
    
    for (i = 0; i < n; i++)
    {
        printf("Ingresa el %d valor\n ~>",i+1);
        scanf("%d",&numeros[i]);
        sum += numeros[i];
    }
    float promedio = sum/n;
    printf("El promedio de los %d numeros es %.3f",n,promedio);
    free(numeros);
}