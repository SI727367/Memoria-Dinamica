#include "contenedor-1.h"
#include <stdbool.h>

long hash(char data[50]){
	int suma=0;
	int factm=1;
	int i = 0;
	while(data[i]) {
		suma=suma+((data[i]-'a'+1) * factm);
		i++;
		factm=factm*2;
	}
	return(suma);
}

LIST list_create(){
	LIST tmp=malloc(sizeof(struct STRLIST));
	tmp->first=NULL;
	tmp->last=NULL;
	tmp->size=0;
	return(tmp);
}

void list_insert(LIST list,char data[50]){
    int i;
    NODE tmp = list->first;
    bool arethesame = true;
    while(tmp != NULL){
        //printf("bibo \n");
        for(i=0; i<50 ;i++){
            if(tmp->value[i] != data[i]){
                arethesame = false;
                break;
            }
        }
        if(arethesame)
            return;
        tmp = tmp->next;
    }
    NODE new = malloc(sizeof(struct STRNODE));
    for(i=0; i<50 ;i++)
        new->value[i] = data[i];
    new->next = NULL;

    if(list->first==NULL)
        list->first = new;
    else
        list->last->next=new;

    list->last = new;
    list->size++;
}
