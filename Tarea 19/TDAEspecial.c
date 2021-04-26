#include "tdaspecial.h"
#include <stdio.h>
#include <stdlib.h>

QUEUE queue_create()
{
	QUEUE tmp=malloc(sizeof(struct STRQUEUE));
	tmp->first=NULL;
	tmp->last=NULL;
	tmp->size=0;
	return(tmp);
}

void queue_offer(QUEUE queue,TYPE element)
{
	NODE new=malloc(sizeof(struct STRNODE));
	stack_push(new->Qstack,element);
	new->next=NULL;
	if(queue->first==NULL)	// Si no hay nada en la cola y es
		queue->first=new;	// el primer elemento
	else
		queue->last->next=new;

	queue->last=new;
	queue->size++;
}

TYPE queue_poll(QUEUE queue)
{
	NODE toerase=queue->first;
	TYPE data=NULL;
	if(toerase!=NULL)
	{
		data=stack_pop(toerase->Qstack);
		queue->first=toerase->next;
		free(toerase);
	}
	queue->size--;
	return(data);
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
	NODESTACK new=malloc(sizeof(struct STRNODESTACK));
	new->data=element;
	new->prev=stack->top;	// El previo al nodo apunta a donde estaba
					// antes el tope
	stack->top=new;
}

int stack_pop_int(STACK stack)
{
	int *ptrnum=stack_pop(stack);
	int num=*ptrnum;
	free(ptrnum);	// Libero la memoria que se reserv� para el entero
	return(num);
}

TYPE stack_pop(STACK stack)
{
	NODESTACK to_erase=stack->top;
	TYPE data=to_erase->data;
	stack->top=to_erase->prev;	// El tope, apunta al elemento previo.
	free(to_erase);
	return(data);
}
