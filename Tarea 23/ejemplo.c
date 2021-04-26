#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pq.c"

int main()
{
	int i;
	int *n;
	TYPE x;

	PQ pq=pq_create(100,print,compare,sizeof(int));

	srand(time(NULL));

	setbuf(stdout,NULL);

	for(i=0;i<20;i++)
	{
		n=malloc(sizeof(int));
		*n=rand()%100;
		pq_offer(pq,n);
	}

	pq_display(pq);

	//
	for(i=0;i<20;i++)
	{
		x=pq_pool(pq); // Obtener un elemento, eliminarlo
					   // y devolverlo
		pq->printfunc(x);
	}

}
