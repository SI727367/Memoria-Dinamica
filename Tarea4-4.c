#include <stdio.h>
void printchar(void *vp, char type[]){
    char i;
    i = *((char *)vp);
    printf(type, i);
}
void printshort(void *vp, char type[]){
    short i;
    i = *((short *)vp);
    printf(type, i);
}
void printint(void *vp, char type[]){
    int i;
    i = *((int *)vp);
    printf(type, i);
}
void printlong(void *vp, char type[]){
    long i;
    i = *((long *)vp);
    printf(type, i);
}
void printfloat(void *vp, char type[]){
    float i;
    i = *((float *)vp);
    printf(type, i);
}
void printdouble(void *vp, char type[]){
    double i;
    i = *((double *)vp);
    printf(type, i);
}
int main(){
    char arr[] = {'A','B',100,20,0x4E,50,60,'M','D',0x25,040};
    printchar(arr, "%d\n");
    printshort(arr, "%X\n");
    printint(arr, "%X");
}
