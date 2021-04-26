#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;

    int matriz[18];

    FILE * archivo = fopen("entrada.bin", "wb");
    if(archivo == NULL){
        printf("VACIO");
        exit(1);
    }

    for(i=0; i<9 ;i++){
        printf("Ingrese el numero %d de la matriz A: \n ~>", i+1);
        scanf("%d", &matriz[i]);
    }
    printf("\n");
    for(i=0; i<9 ;i++){
        printf("Ingrese el numero %d de la matriz B: \n ~>", i+1);
        scanf("%d", &matriz[i+9]);
    }

    fwrite(matriz, sizeof(int), 18, archivo);
    fclose(archivo);
    return 0;
}
