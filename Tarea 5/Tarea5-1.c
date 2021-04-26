#include <stdio.h>
#include <stdbool.h>
int i,j;
int main(){
    int Min, Max,g = 0;
    printf("Ingrese valor minimo \n~>");
    scanf("%d",&Min);
    printf("Ingrese valor maximo \n~>");
    scanf("%d",&Max);
    

    for (i = Min; i < Max+1; i++)
    {
        int k = 0;
        bool Primo = true;
        if (i < 2){
            Primo = false;
        }
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                k++;
            }
            if (k >= 1)
            {
                Primo = false;
                break;
            }
        }
        if (Primo == true)
        {
            g++;
            printf("%d\n",i);
        }
    }
    printf("La cantidad de numeros primos entre %d y %d es %d",Min,Max,g);
}