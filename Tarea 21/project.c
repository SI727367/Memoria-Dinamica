#include <stdio.h>
#include <string.h>
#include "set.c"

int comparefunc(TYPE data1,TYPE data2);
void printfunc(TYPE data);
void destructfunc(TYPE data);
void NumARomano(int n, char* rome);

int main(){
    SET nums = set_create(comparefunc,printfunc,destructfunc);
    SET romano = set_create(comparefunc,printfunc,destructfunc);

    int i,n;
    char rome[50];
    for(i=0;i<10;i++){
        n = rand()%101;
        set_insert(nums,n);
        NumARomano(n, &rome[0]);
        set_insert(romano, rome);
    }
    set_print(nums);
    set_print(romano);
    return 0;
}

int comparefunc(TYPE data1,TYPE data2)
{
	return(strcmp((char *)data1,(char *)data2));
}

void printfunc(TYPE data)
{
	printf("%s\n",(char *) data);
}

void destructfunc(TYPE data)
{
	free((char *) data);
}

void NumARomano(int n, char* rome){
    int decimal, unidad, centenar;
    unidad = n%10;
    decimal = n/10;
    centenar = n/100;
    if(centenar == 1){
        rome+='C';
    }
    switch(decimal){
        case 1:
            rome+='X';
            break;
        case 2:
            rome+='X';
            rome+='X';
            break;
        case 3:
            rome+='X';
            rome+='X';
            rome+='X';
            break;
        case 4:
            rome+='X';
            rome+='L';
            break;
        case 5:
            rome+='L';
            break;
        case 6:
            rome+='L';
            rome+='X';
            break;
        case 7:
            rome+='L';
            rome+='X';
            rome+='X';
            break;
        case 8:
            rome+='L';
            rome+='X';
            rome+='X';
            rome+='X';
            break;
        case 9:
            rome+='X';
            rome+='C';
            break;
    }
    switch(unidad){
        case 1:
            rome+='I';
            break;
        case 2:
            rome+='I';
            rome+='I';
            break;
        case 3:
            rome+='I';
            rome+='I';
            rome+='I';
            break;
        case 4:
            rome+='I';
            rome+='V';
            break;
        case 5:
            rome+='V';
            break;
        case 6:
            rome+='V';
            rome+='I';
            break;
        case 7:
            rome+='V';
            rome+='I';
            rome+='I';
            break;
        case 8:
            rome+='V';
            rome+='I';
            rome+='I';
            rome+='I';
            break;
        case 9:
            rome+='I';
            rome+='X';
            break;
    }
}
