#include <stdio.h>
#include "arbol.c"

int main()
{
  SET test = create_set();
  int dato, compareInt;


  do{
    printf("Ingresa un elemento de la lista: ");
    scanf("%d",&dato);
    if(dato != 0)
        tree_insert(test, dato);
  } while(dato != 0);
  
  printf("Dato a comparar: ");
  scanf("%d",&compareInt);

  
  int sum = sumGreaterThan(test->root, compareInt);
  
  printf("Suma: [%d]\n", sum);
}