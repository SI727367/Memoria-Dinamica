#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef void* TYPE;

struct STRNODE {
	TYPE data;
	struct STRNODE *prev;
};

typedef struct STRNODE* NODE;

struct STRSTACK {
	NODE top;
	int size;
};

typedef struct STRSTACK* STACK;

STACK stack_create();
void stack_push(STACK s,TYPE e);
TYPE stack_pop(STACK s);

int str_size(char str[100]);
int precedencia(char op);

int main(){
    //Recibe operacion
    char inf[100];
    printf("Ingrese la operaci�n (no ingrese espacios): \n ~> ");
    scanf("%s", &inf);
    int cache1 = str_size(inf)+1;
    inf[cache1]="\0";
    //crear cosas
    STACK pos = stack_create();
    STACK ope = stack_create();
    int i, j;
    char *top;
    //recorrer string infija
    for(i=0 ; i<str_size(inf) ; i++){
        if((inf[i]>='0' && inf[i]<='9') || (inf[i]>='a' && inf[i]<='z') || (inf[i]>='A' && inf[i]<='Z')){
            //si es un numero, meter y ya
            printf("num: %c\n", inf[i]);
            stack_push(pos,inf[i]);
        }
        else if(inf[i]=='+' || inf[i]=='-' || inf[i]=='*' || inf[i]=='/' || inf[i]==')'){
            top = stack_pop(ope); //////////////////// ESTA LINEA MATA AL CODIGO
            printf("operador: %c vs %c: ", inf[i], top);
            if(inf[i] == ')'){
                //vaciar stack
                printf(")\n");
                for(j=0; j<ope->size ;j++)
                    stack_push(pos,stack_pop(ope));
            }
            else if(precedencia(inf[i])==precedencia(top)){
                //cambia
                printf("=\n");
                stack_push(pos,stack_pop(ope));
                stack_push(ope,inf[i]);
            }
            else if(precedencia(inf[i])>precedencia(top)){
                //agrega a stack
                printf(">\n");
                stack_push(ope,inf[i]);
            }
            else if(precedencia(inf[i])<precedencia(top)){
                //vacia stack y luego agrega a stack
                printf("<\n");
                for(j=0; j<ope->size ;j++)
                    stack_push(pos,stack_pop(ope));
                stack_push(ope,inf[i]);
            }
            stack_push(ope, top);
        }
    }
    //vaciar stack
    printf("vaciar\n");
    for(j=0; j<ope->size ;j++)
        stack_push(pos,stack_pop(ope));
    //imprimir stack posfijo
    STACK fin = stack_create();
    int n = pos->size;
    printf("El resultado es: ");
    for(i=0; i<n ;i++)
        stack_push(fin,stack_pop(pos));
    for(i=0; i<n ;i++)
        printf("%c", stack_pop(fin));

	return 0;
}

int str_size(char str[100]){
    int i = 0;
    while(str[i] != 0)
        i++;
    return i;
}

int precedencia(char op){
    if(op == '+' || op == '-')
        return 1;
    else if(op == '*' || op == '/')
        return 2;
    else
        return 0;
}

STACK stack_create(){
	STACK tmp=malloc(sizeof(struct STRSTACK));
	tmp->top=NULL;
	tmp->size=0;
	return(tmp);
}

void stack_push(STACK stack,TYPE element){
	NODE new=malloc(sizeof(struct STRNODE));
	new->data=element;
	new->prev=stack->top;	// El previo al nodo apunta a donde estaba
                            // antes el tope
	stack->top=new;
	stack->size++;
}

TYPE stack_pop(STACK stack){
	NODE to_erase=stack->top;
	TYPE data=to_erase->data;
	stack->top=to_erase->prev;	// El tope, apunta al elemento previo.
	free(to_erase);
	stack->size--;
	return(data);
}
