#include <stdio.h>
#include <stdlib.h>
#include "stack.c"



int main(){
    int contador = 4;
    int seccion = 0;
    int lista[20];
    STACK stack = stack_create();
    
    while (seccion < 5)
    {
        printf("Se generaron:");
        //Numeros aleatorios
        for (size_t i = 0; i < 4; i++){
            int random = rand() % 50; //No se puede con time.h porque se generan demasiado rapido como para que sean diferentes el set de 4
            printf("%d ",random); //RECUERDA DESCOMENTAR ESTO____________________________________________________________
            stack_push_int(stack, random);
        }
        int largo =  stack_size(stack);
        //Ordenamiento
        
        int y = 0;
        while(stack_isempty(stack)!= 1){
            lista[y] = stack_pop_int(stack);
            y++;
        }

        /*for (size_t i = 0; i < largo; i++)
        {
            printf("%d ",lista[i]);
        }*/


        for (size_t i = 0; i < largo; i++)
        {
            for (size_t j = 0; j < largo-1; j++)
            {
                if (lista[i] > lista [j])
                {
                    int c = lista[i];
                    lista[i] = lista[j];
                    lista[j] = c;
                }
                
            }
        }
        
        printf("Se tiene almacenado:)");
        for (size_t i = 0; i < largo; i++)
        {
            printf("%d ",lista[i]);
        }

        for (size_t i = 0; i < largo; i++)
        {
            stack_push_int(stack, lista[i]);
        }

        printf("Menor = %d ",stack_pop_int(stack));
        printf("\n");

        seccion += 1;
        contador += 4;
    }

    printf("Se tiene almacenado:");
    for (size_t i = 0; i < 15; i++)
    {
        printf("%d ",stack_pop_int(stack));
    }
}
