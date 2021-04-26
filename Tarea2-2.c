#include <stdio.h>
void swap(char *pa, char *pb){
    int c = *pa;
    int i;
    for(i = 0;i<10;i++){
        c = *pa;
        *pa = *pb;
        *pb = c;
        pa++;
        pb++;
    }

}

void sortnames(char pnombres[][10], int l){
    int i, j;
    char *buff, *b2;
    char *name = *pnombres;
    char *name2 = *pnombres;
    for(i = 1; i<9;i++){
        name = *pnombres;
        name2 = *pnombres;
        for(j = 0; j <= i; j++){
            name += 10;
            int k = 0;
            buff = name;
            b2 = name2;
            while(*name == *name2){
                name++;
                name2++;
                k++;
            }
            if(*name < *name2){
              swap(buff, b2);
            }
            name = buff;
            name2 = b2;
            name2 += 10;
        }
    }
    name = *pnombres;
    printf("\nLos nombres ordenados son:\n");
    for(i=0;i<10;i++){
        printf("#%d %s\n", i+1,name);
        name += 10;
    }
}
int main(){
    int i;
    char nombres[10][10];
    for(i = 0; i<10;i++){
        printf("\nIngrese nombre #%d\n~>",i+1);
        scanf("%s", nombres[i]);
    }
    sortnames(nombres,10);
}
