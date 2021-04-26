/*
 * ejemplohash1.c
 *
 *  Created on: 17/11/2020
 *      Author: jluis
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* TYPE;

struct STRNODE {
	TYPE key,value;
	struct STRNODE* next;
};

typedef struct STRNODE* NODE;

struct STRLIST {
	NODE first,last;
	int size;
};

struct KEYVAL {
	char key[50];
	char value[50];
};

typedef struct STRLIST* LIST;

#define M 10

long long myhash(TYPE data);
LIST list_create();
void list_insert(LIST list,TYPE data);


int main()
{
	int i;
	int pos;
	LIST lista[M];
	struct KEYVAL kv;
	long long hashcode;

	setbuf(stdout,NULL);
	// Crear las listas
	for(i=0;i<M;i++)
		lista[i]=list_create();

	do {
		printf("Dame una llave ");
		scanf("%s",kv.key);
		printf("Dame un valor ");
		scanf("%s",kv.value);

		hashcode=myhash(kv.key);
		printf("El código generado es : %I64x\n",hashcode);
		pos=hashcode % M;
		printf("Posición de la tabla : %d\n",pos);
		list_insert(lista[pos],&kv);
	} while(strcmp(kv.key,"FIN")!=0);

    //printf("%s %s",lista[0]->first->key,lista[0]->first->value);
    
    for (size_t i = 0; i < 10; i++)
    {
        print_list(lista[i]);
    }
}

long long myhash(TYPE data)
{
	int suma=0;
	int factm=1;
	char *cad=data;
	while(*cad) {
		suma=suma+(*cad * factm);
		cad++;
		factm=factm*2;
	}
	return(suma);
}

LIST list_create()
{
	LIST tmp=malloc(sizeof(struct STRLIST));
	tmp->first=NULL;
	tmp->last=NULL;
	tmp->size=0;
	return(tmp);
}

void list_insert(LIST list,TYPE data)
{
    struct KEYVAL *kv=data;
    if (kv->key == "FIN")
        return;
    
    NODE yeet = malloc(sizeof(struct STRNODE));
    NODE ptr = list->first;
    NODE pvr = NULL;
    yeet->next = NULL;
    yeet->key = kv->key;
    yeet->value = kv->value;
    
    

    if (list->size == 0)
    {
        list->first = yeet;
    }
    else
    {
        list->last->next = yeet;
    }
    list->last = yeet;
    list->size++;
    
	printf("Insertando el par <%s,%s>\n",kv->key,kv->value);
    //printf("%s %s",list->last->key,list->last->value);
}

void print_list(LIST list){
    NODE prent = list->first;
    
    while (prent != NULL)
    {
        printf("%s %s\n",prent->value,prent->key);
        prent = prent->next;
    }
}
