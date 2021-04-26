#include "queues.h"
#include <stdbool.h>

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
	new->data=element;
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
		data=toerase->data;
		queue->first=toerase->next;
		free(toerase);
	}
	queue->size--;
	return(data);
}

TYPE queue_peek(QUEUE queue){
	TYPE data=queue->first->data;
	return(data);
}

void queue_destroy(QUEUE queue){
	NODE toerase=queue->first;
	TYPE data=NULL;
	while(toerase!=NULL)
	{
		data=toerase->data;
		queue->first=toerase->next;
		free(toerase);
	}
	queue->size--;
}

bool queue_isempty(QUEUE queue){
	int isempty;
    if(queue->first == NULL){
        isempty = true;
    }else{
        isempty = false;
    }
    return isempty;
}

int queue_size(QUEUE queue){
	return queue->size;
}