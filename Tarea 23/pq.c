#include "pq.h"
#define left(n) (n*2+1)
#define right(n) (n*2+2)


int compare(TYPE d1,TYPE d2)
{
	int i1=*((int *) d1);
	int i2=*((int *) d2);
	return(i1-i2);
}

void print(TYPE d)
{
	printf("%d\n",*((int *) d));
}

void pq_offer(struct STRPQ *pq,TYPE data)
{
	int e=pq->size;
	int p;

	pq->arr[e]=data;
	pq->size++;

	do {
		p=(e-1)/2;

		if(pq->comparefunc(pq->arr[p],pq->arr[e])>0)
			swap(pq->arr[e],pq->arr[p],pq->size_of_data);

		e=p;
	} while(p>0);
}

void pq_display(PQ pq)
{
	recorre(pq,0,0,pq->printfunc);
}


void recorre(struct STRPQ *pq,int elem,int spaces,PRINTFUNC printfunc)
{
	int i;
	if(elem < pq->size)
	{
		for(i=0;i<spaces;i++)
			printf("\t");
		printfunc(pq->arr[elem]);

		recorre(pq,left(elem),spaces+1,printfunc);

		recorre(pq,right(elem),spaces+1,printfunc);

	}
}

PQ pq_create(int maxsize,PRINTFUNC printfunc,COMPAREFUNC comparefunc,int size_of_data)
{
	PQ tmp=malloc(sizeof(struct STRPQ));
	tmp->arr=malloc(maxsize*sizeof(int));
	tmp->size=0;
	tmp->comparefunc=comparefunc;
	tmp->printfunc=printfunc;
	tmp->size_of_data=size_of_data;
	return(tmp);
}



void swap(TYPE d1,TYPE d2,int size)
{
	TYPE tmp=malloc(size);
	memmove(tmp,d1,size);	// Función para mover bloques de memoria
	memmove(d1,d2,size);
	memmove(d2,tmp,size);
	free(tmp);
}

TYPE pq_pool(PQ pq)
{
	int weight = 0;
    TYPE cache = malloc(sizeof(pq->size_of_data));
    cache = pq->arr[weight];

    while(right(weight)<=pq->size){

        if(compare(pq->arr[left(weight)],pq->arr[right(weight)])>=0){
            swap(pq->arr[weight],pq->arr[left(weight)],pq->size_of_data);
            weight = left(weight);
        }
        else{
            swap(pq->arr[weight],pq->arr[right(weight)],pq->size_of_data);
            weight = right(weight);
        }
    }
    free(pq->arr[weight]);
    pq->size--;

    return cache;
}