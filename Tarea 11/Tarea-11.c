#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fd;
    int ma[3][3], mb[3][3], mc[3][3];
    int i, j;
    fd = fopen("a.txt", "r");
    if(fd==NULL){
        fprintf(stderr, "Error al abrir el archivo");
        exit(1);
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(!feof(fd)){
                fscanf(fd,"%d",&ma[i][j]);
            }
        }
    }
    fclose(fd);
    fd = fopen("b.txt", "r");
    if(fd==NULL){
        fprintf(stderr, "Error al abrir el archivo");
        exit(1);
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(!feof(fd)){
                fscanf(fd,"%d",&mb[i][j]);
            }
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            mc[i][j]=ma[i][j]*mb[i][j];
        }
    }
    fclose(fd);
    fd = fopen("c.txt", "w");
    if(fd==NULL){
        fprintf(stderr, "Error al abrir archivo");
        exit(1);
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(j<2){
              fprintf(fd,"%d,", mc[i][j]);
            }else{
            fprintf(fd,"%d", mc[i][j]);
            }

        }
        fprintf(fd, "\n");
    }
}