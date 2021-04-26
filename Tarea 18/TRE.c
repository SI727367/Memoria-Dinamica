#include <stdio.h>
#include <stdlib.h>

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
void stack_push_int(STACK stack,int num);
int stack_pop_int(STACK stack);
int str_size(char str[100]);
int presedencia(TYPE b);
int stack[100];




int main()
{
	char expresion[100];
    //char futuro[100];
    STACK operadores = stack_create();
    STACK fin = stack_create();
    STACK chido = stack_create();
    int i;
    printf("Escriba su expresion: ");
    scanf("%s", &expresion);
    /*i=0;
    while(expresion[i] != '\0'){
        printf("%c", expresion[i]);
        i++;
    }
    */
    int n = str_size(expresion);
    stack_push(operadores,"^");
   // printf("\n");
    for(i=0;i<n;i++){
        if((expresion[i]>='0' && expresion[i]<='9') || (expresion[i]>='a' && expresion[i]<='z') || (expresion[i]>='A' && expresion[i]<='Z')){
            //printf("Valor: %c\n", expresion[i]);
            stack_push(fin, expresion[i]);

        }else{
            if(expresion[i] == ')'){
               // printf("WHILE\n");
                while(operadores->top->data != '('){
                    stack_push(fin, stack_pop(operadores));
                    //printf("%c", stack_pop(fin));
                }
                stack_pop(operadores);
                if(operadores->top == NULL){
                  stack_push(operadores,"^");
                }


            }else if(expresion[i] == '('){
                stack_push(operadores,'(');
            }else{

               // printf("ELSE\n");
                if(presedencia(&expresion[i]) == presedencia(&operadores->top->data)){
                    stack_push(fin, stack_pop(operadores));
                    //printf("%c", stack_pop(fin));
                }else if(presedencia(&expresion[i]) < presedencia(&operadores->top->data)){
                    //printf("WHILE\n");
                    while(operadores->top != NULL){
                        stack_push(fin, stack_pop(operadores));
                    //printf("%c", stack_pop(fin));
                    }
                }
                stack_push(operadores, expresion[i]);
            }
        }
    }
    //print_futuro(&expresion[0], n);
    while(operadores->top != NULL){
        stack_push(fin, stack_pop(operadores));
                    //printf("%c", stack_pop(fin));
    }
    while(fin->top != NULL){
        stack_push(chido, stack_pop(fin));
    }
    /*while(chido->top != NULL){
        if(chido->top->data != "^"){
            printf("%c", stack_pop(chido));
        }else{
            stack_pop(chido);
        }
    }*/

    int n1,n2,n3,num[100];
    char *e;
    e = chido;

    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            stack_push_int(num,e);
        }
        else
        {
            n1 = stack_pop_int(num);
            n2 = stack_pop_int(num);
            switch(*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                stack_push_int(num,n3);
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                stack_push_int(num,n3);
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                stack_push_int(num,n3);
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                stack_push_int(num,n3);
                break;
            }
            case '^':
            {
                break;
            }
            }
        }
        e++;
    }
    printf("\nEl resultado de la operacion es: %s  =  %d\n\n",chido,stack_pop_int(num));
    return 0;
}

STACK stack_create()
{
	STACK tmp=malloc(sizeof(struct STRSTACK));
	tmp->top=NULL;
	tmp->size=0;
	return(tmp);
}

void stack_push_int(STACK stack,int num)
{
	int *ptrnum=malloc(sizeof(int));
	*ptrnum=num;
	stack_push(stack,ptrnum);
}

void stack_push(STACK stack,TYPE element)
{
	NODE new=malloc(sizeof(struct STRNODE));
	new->data=element;
	new->prev=stack->top;	// El previo al nodo apunta a donde estaba
					// antes el tope
	stack->top=new;
}

int stack_pop_int(STACK stack)
{
	int *ptrnum=stack_pop(stack);
	int num=*ptrnum;
	free(ptrnum);	// Libero la memoria que se reservу para el entero
	return(num);
}

TYPE stack_pop(STACK stack)
{
	NODE to_erase=stack->top;
	TYPE data=to_erase->data;
	stack->top=to_erase->prev;	// El tope, apunta al elemento previo.
	free(to_erase);
	return(data);
}
int str_size(char str[100]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    //printf("%d\n", i);
    return i;
}

int presedencia(TYPE b){
    char*a = b;
  //  printf("PRESENDENCIA\n");
  //  printf("%c", *a);
    if(*a == '*' || *a == '/'){
       // printf("2\n");
        return 2;
    }else if(*a == '+' || *a == '-'){
        //printf("1\n");
        return 1;
    }else{
        //printf("0\n");
        return 0;
    }
}

