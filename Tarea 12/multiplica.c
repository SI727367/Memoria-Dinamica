#include <stdio.h>
#include <stdlib.h>

int main(){
    int matriz[18];
    int MATA[3][3];
    int MATB[3][3];
    int MATC[3][3];
    int i, j;

    //Extrae lista
    FILE * archivo = fopen("entrada.bin", "rb");
    if(archivo == NULL){
        printf("ERROR");
        exit(1);
    }
    fread(matriz, sizeof(int), 18, archivo);
    fclose(archivo);
    //Convierte lista a matrices
    for(i=0; i<3 ;i++){
        for(j=0; j<3 ;j++){
            MATA[i][j] = matriz[3*i+j];
            MATB[i][j] = matriz[3*i+j+9];
        }
    }
    //Calcula C
    for(i=0; i<3 ;i++){
        for(j=0; j<3 ;j++){
            MATC[i][j] = MATA[i][0]*MATB[0][j] + MATA[i][1]*MATB[1][j] + MATA[i][2]*MATB[2][j];
            //printf("%d\t", C[i][j]);
        }
        //printf("\n");
    }
    //Guarda C
    FILE * archivo2 = fopen("salida.bin", "wb");
    if(archivo2 == NULL){
        printf("ERROR");
        exit(1);
    }
    fwrite(MATC, sizeof(int), 9, archivo2);
    fclose(archivo2);
    return 0;
}
