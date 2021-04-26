#include "lista.h"
#include <stdio.h>
LIST list_create()
{
	LIST tmp=malloc(sizeof(struct STRLIST));
	tmp->first=NULL;
	tmp->last=NULL;
	tmp->size=0;
	tmp->prefirst=malloc(sizeof(struct STRNODE));
	tmp->postlast=malloc(sizeof(struct STRNODE));
	tmp->prefirst->prior=NULL;
	tmp->prefirst->data=NULL;
	tmp->postlast->next=NULL;
	tmp->postlast->data=NULL;
	return(tmp);
}

void list_insert_int(LIST list,int n)
{
	int *intptr=malloc(sizeof(int));
	*intptr=n;
	list_insert(list,intptr);
}

void list_insert(LIST list,TYPE data)
{
	NODE new=malloc(sizeof(struct STRNODE));
	new->data=data;
	new->next=NULL;
	new->prior=NULL;

	if(list->first==NULL)	// La lista estб vacнa
	{
		list->first=new;
		list->prefirst->next=list->first;
	}
	else
	{
		new->prior=list->last;
		list->last->next=new;
	}
	list->last=new;
	list->postlast->prior=list->last;
	list->size++;
}

TYPE list_remove(LIST list, int i){
    ITERATOR iterator = list_get(list, i);
   // printf("DENTRO REMOVE\n");
    NODE to_erase = iterator;
    TYPE data = to_erase->data;
   // int num =iterator_data(iterator);
   // printf("%d\n", num);
    if(list->size == 1){
        //printf("PRIMER IF\n");
        list->first = NULL;
        list->last = NULL;
    }else if(iterator==list->first){
        //printf("SEGUNDO IF\n");
        list->first->next->prior = NULL;
        list->prefirst->next = list->first->next;
        list->first = list->first->next;

    }else if(iterator==list->last){
        //printf("TERCERO IF\n");
        list->last->prior->next = NULL;
        list->postlast->prior = list->last->prior;
        list->last = list->last->prior;
    }else{
        //printf("CUARTO IF\n");
        iterator->prior->next = iterator->next;
        iterator->next->prior = iterator->prior;
    }
    printf("DESPUES IFS\n");
    list->size--;
    free(to_erase);
    return(data);
}

ITERATOR list_get(LIST list, int i){
     //printf("DENTRO GET\n");
     int cont = 0;
     ITERATOR iterator;
     iterator = list_begin(list);
     if(i>=list->size || i < 0){
        return NULL;
     }
     while(cont <= i){
        if(has_next(iterator)==0){
            return NULL;
        }
        iterator = list_next(iterator);
        cont++;
     }
     return(iterator);
}

void list_set(LIST list, TYPE data, int i){
   // int *intptr = data;
   // int n,n2;
    //TYPE new_data = intptr;
    NODE to_change = list_get(list, i);

   // n2=(int*)data;
    to_change->data = data;
    //n=iterator_data(to_change);

   // printf("TEORIA: %d OTRO: %d\n", n, n2);
}
