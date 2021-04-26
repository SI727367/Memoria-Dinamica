#include <stdio.h>
#include "stack.h"

int main(){
    STACK stack = stack_create();
    char str[5] = "HOLA";
    stack_push(stack, str);
    str[5] = "MUNDO";
    stack_push(stack, str);
    str[5]= "ESP";
    stack_push(stack, str);
    while(stack_isempty(stack)!= 1){
        printf("%s\n", stack_pop(str));
    }
}
