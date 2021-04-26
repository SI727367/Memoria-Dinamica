#include <stdio.h>

void printptrarr(char **a,int n) {
    for (size_t i = 0; i < 12; i++){
       while (*a[0] != '\0'){
           printf("%c",*a[0]);
           *a[0]++;
        }
        
        printf("\n");
        *a++;
    }
}

int main(){

    char arr[][10]={"Uno","Dos","Tres","Cuatro","Cinco","Seis","Siete","Ocho","Nueve","Diez","Once","Doce"};
    char *parr[12];
    for (size_t i = 0; i < 12; i++)
    {
        parr[i] = &arr[i];
    }

    printptrarr((parr),12);
}