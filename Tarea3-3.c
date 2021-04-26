#include <stdio.h>

void ejecutar(void (*func_a)(void)){
    func_a();
}

void saludar()
{
    printf("Hola\n");
}

int main()
{
    ejecutar(saludar); // La función ejecutar va a ser que se ejecute la función
                        // saludar
}
