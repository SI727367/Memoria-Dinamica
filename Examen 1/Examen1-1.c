#include <stdio.h>
#define SIZE 10
int i = 0;

int suma(int a,int b)
{
    return(a+b);
}

int resta(int a,int b)
{
    return(a-b);
}

int mult(int a,int b)
{
    return(a*b);
}


void printvec(int *v,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",*v);
         v++;
    }
    printf("\n");
}

void opvec(int *v[3], int n,int (*func)(int,int)){
    for (i = 0; i < n; i++)
    {
        int p1, p2, f;
        p1 = *(*(v)+i);
        p2 = *(*(v+1)+i);
        f = func(p1,p2);
        
        *(*(v+2)+i) = f;
    }
}

int main()
{
    int i;
    int v1[SIZE]={9,8,7,6,5,4,3,2,1,0};
    int v2[SIZE]={0,1,2,3,4,5,6,7,8,9};
    int v3[SIZE];
    
    int *vectores[3]={v1,v2,v3};


    opvec(vectores,SIZE,suma);
    printf("La suma de los vectores a y b =");
    printvec(v3,SIZE);

    opvec(vectores,SIZE,resta);
    printf("La resta de los vectores a y b =");
    printvec(v3,SIZE);

    opvec(vectores,SIZE,mult);
    printf("La multiplicación de los vectores a y b =");
    printvec(v3,SIZE);

    return 0;
}