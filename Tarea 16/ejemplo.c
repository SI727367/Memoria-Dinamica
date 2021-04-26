#include <stdio.h>
//#include "queues.h"
#include "queues.c"

int main()
{
	char s1[10]="Jonathan";
	char s2[10]="Malex";
	char s3[10]="Myke";
	char *s;

	QUEUE q=queue_create();

	printf("Cola creada\n");
	queue_offer(q,s1);
	queue_offer(q,s2);
	queue_offer(q,s3);

	while((s=queue_poll(q))!=NULL)
		printf("%s\n",s);
	
}

