#include <stdio.h>

void imprimirdoble(int n){
    n *= 2;
    printf("%d\n",n);
}

void imprimirtriple(int n){
    n *= 3;
    printf("%d\n",n);
}

int sumar(int a,int b){
    int c = a + b;
    return c;
}

int restar(int a,int b){
    int c = a - b;
    return c;
}

int main(){

    void (*func_a)(int) = 0;
    int (*func_b)(int,int) = 0;

    func_a = imprimirdoble;
    func_a(5);
    func_a = imprimirtriple;
    func_a(5);

    func_b = sumar;
    printf("%d\n",func_b(5,5));
    func_b = restar;
    printf("%d\n",func_b(5,5));

}