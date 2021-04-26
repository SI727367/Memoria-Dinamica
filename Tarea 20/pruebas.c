#include "set.c"
#include <stdio.h>

int main(){
    //printf("ANTES CREATE");
    TREE arbol = tree_create();
    int i,n;
    //printf("ANTES DE INSERTAR");
    for(i=0;i<20;i++){
        n=rand()%100;
        tree_insert(arbol, n);
    }
    //printf("INSERTO");
    inorden(arbol->root);
    return 0;
}
