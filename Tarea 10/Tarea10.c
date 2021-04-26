#include <stdio.h>
#include "rectangle.h"

int main()
{
    rectangle r1=new_rectangle(10.0,20.0);

    printf("Base del rectángulo %.2f\n",base(r1));           // Deberá mostrar 10 en pantalla
    printf("Altura del rectángulo %.2f\n",height(r1));       // Deberá mostrar 20 en pantalla
    printf("Área del rectángulo %.2f\n",area(r1));           // Deberá mostrar 200 en pantalla
    printf("Perínetro del rectángulo %.2f\n",perimeter(r1));  // Deberá mostrar 60 en pantalla

    set_base(r1,12.0);
    set_height(r1,15.0);

    printf("Base del rectángulo %.2f\n",base(r1));           // Deberá mostrar 12 en pantalla
    printf("Altura del rectángulo %.2f\n",height(r1));       // Deberá mostrar 15 en pantalla
}