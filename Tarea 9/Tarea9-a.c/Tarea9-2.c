#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int i,j, k, x, y;
    time_t t;
    srand((unsigned) time(&t));
    printf("Renglones:\n");
    scanf("%d", &x);
    printf("Columnas: \n");
    scanf("%d", &y);
    int **mat1 = malloc(x*sizeof(int));
    int **mat2 = malloc(x*sizeof(int));
    int **mat3 = malloc(x*sizeof(int));
    for(i=0;i<x;i++){
        mat1[i] = malloc(y*sizeof(int));
        mat2[i] = malloc(y*sizeof(int));
        mat3[i] = malloc(y*sizeof(int));
        for(j=0;j<y;j++){
            mat1[i][j] = rand()%11;
            mat2[i][j] = rand() % 11;
            mat3[i][j] = 0;
        }
    }
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            mat3[i][j] = mat1[i][j] * mat2[i][j];
        }
    }
    for(i=0;i<x;i++){
        for(j=0;j<3;j++){
                for(k=0;k<y;k++){
                    if(j == 0){
                        printf("%02d ", mat1[i][k]);
                    }else if(j==1){
                        printf("%02d ", mat2[i][k]);
                    }else{
                        printf("%02d ", mat3[i][k]);
                    }
                }
                printf("    ");
        }
        printf("\n");
    }
    return 0;
}