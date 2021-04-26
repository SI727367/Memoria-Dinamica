#include <stdio.h>
#include <stdlib.h>

int main(){
    int matriz[9];
    int i;

    FILE * archivo = fopen("salida.bin", "rb");
    if(archivo == NULL){
        printf("ERROR");
        exit(1);
    }
    fread(matriz, sizeof(int), 9, archivo);
    fclose(archivo);

    printf("C = [");
    for(i=0; i<9 ;i++){
        if(i==8)
            printf("%d", matriz[i]);
        else
            printf("%d ,", matriz[i]);
    }
    printf("] \n");
}
