#include <stdio.h>
#include "stack.h"

int precedencia(char op);

int main()
{
	STACK stack=stack_create();

	char str[100];
	printf("Ingrese una operacion con notacion infija: \n ~> ");
	scanf("%s", &str);

	int i=0;
	int j;
	char fin[100];
	int k = 0;
	while(str[i]!=0){
        if((str[i]>='0' && str[i]<='9') || (str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            //printf("num: %c\n", str[i]);
            fin[k] = str[i];
            k++;
        }
        else if(str[i]==')'){
            //printf("Parentesis \n");
            while(stack_top_char(stack)!='('){
                fin[k] = stack_pop_char(stack);
                k++;
            }
            stack_pop_char(stack);
        }
        else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='('){
            if(stack_size(stack)!=0){
                //printf("Operador: %c vs %c: \n", str[i], stack_top_char(stack));
                //printf("          %d vs %d: \n", precedencia(str[i]), precedencia(stack_top_char(stack)));
            }
            if(stack_size(stack)==0 || str[i] == '('){
                //printf("Operador: %c \n", str[i]);
                stack_push_char(stack, str[i]);
            }
            else if(precedencia(str[i])==precedencia(stack_top_char(stack))){
                //printf(" = \n");
                fin[k] = stack_pop_char(stack);
                k++;
                stack_push_char(stack, str[i]);
            }
            else if(precedencia(str[i])>precedencia(stack_top_char(stack))){
                //printf(" > \n");
                stack_push_char(stack, str[i]);
            }
            else if(precedencia(str[i])<precedencia(stack_top_char(stack))){
                //printf(" < \n");
                while(stack_size(stack)>0){
                    fin[k] = stack_pop_char(stack);
                    k++;
                }
                stack_push_char(stack, str[i]);
            }
        }
        i++;
	}
	while(stack_size(stack)>0){
        fin[k] = stack_pop_char(stack);
        k++;
    }

	fin[k] = '\0';
	printf("\nLa notación postfija es: %s \n", fin);

	return 0;
}

int precedencia(char op){
    if(op == '+' || op == '-')
        return 1;
    else if(op == '*' || op == '/')
        return 2;
    else
        return 0;
}
