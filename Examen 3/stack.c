#include "stack.h"

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
	stack->size++;
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
	free(ptrnum);	// Libero la memoria que se reservó para el entero
	stack->size--;
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

int stack_isempty(STACK stack){
    int isempty;
    if(stack->top == NULL){
        isempty = 1;
    }else{
        isempty = 0;
    }
    return isempty;
}

int stack_size(STACK stack){
    return stack->size;
}