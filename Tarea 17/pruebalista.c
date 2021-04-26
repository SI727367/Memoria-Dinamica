#include <stdio.h>
#include "lista.h"

int main()
{
	LIST list=list_create();
	ITERATOR iterator;
	int num;
	int i;
	int *intptr =malloc(sizeof(int));
	int n;

	setbuf(stdout,NULL);
	for(i=0;i<10;i++)
	{
		printf("Dame un nъmero :");
		scanf("%d",&num);
		list_insert_int(list,num);
	}
	iterator=list_begin(list);
	while(has_next(iterator))
	{
		iterator=list_next(iterator);
		num=iterator_data(iterator);
		printf("%d\n",num);
	}
	printf("\n");
	iterator=list_end(list);
	while(has_prior(iterator))
	{
		iterator=list_prior(iterator);
		num=iterator_data(iterator);
		printf("%d\n",num);
	}

	list_remove(list,0);
	iterator=list_begin(list);
	while(has_next(iterator))
	{
		iterator=list_next(iterator);
		num=iterator_data(iterator);
		printf("%d\n",num);
	}
	printf("SIZE: %d\n", list->size);
	n = 5;
	*intptr = n;
	list_set(list, intptr, 8);
	iterator=list_begin(list);
	while(has_next(iterator))
	{
		iterator=list_next(iterator);
		num=iterator_data(iterator);
		printf("%d\n",num);
	}

	return 0;
}
