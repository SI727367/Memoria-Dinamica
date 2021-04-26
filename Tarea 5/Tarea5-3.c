#include <stdio.h>

int main(){
    int Iteraciones,i;
    float PI = 1.0,k = 3;
    printf("Cuantas iteraciones?");
    scanf("%d",&Iteraciones);

    for (i = 2; i <= Iteraciones; i++)
    {
        float cache = 1/k;
        if (i % 2 == 0){
            PI -= cache;
        }
        if (i % 2 == 1){
            PI += cache;
        }
        k = k + 2;
        //printf("%f\n",4*PI);
		printf("%f\n",cache);
    }
    printf("El valor Pi es %f",4*PI);
}