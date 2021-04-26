#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct NODO {
	int num;
	struct NODO *next;
};

void list_insert(struct NODO **head,int n);
void list_display(struct NODO *ptr, int *n,int *e);


int main()
{
	struct NODO *head=NULL;
	int i;
	int n;
	int elems,errs,calif;
	
	srand(time(NULL));
	
	for(i=0;i<20;i++)
	{
		n=rand()%1000;
		list_insert(&head,n);
	}
	
	list_display(head,&elems,&errs);
	printf("\n");
	printf("%d elementos desplegados, y %d errores\n",elems,errs);
	
	calif=5*elems-20*errs;
	if(calif<0)
		calif=0;
	printf("Calificación = %d\n",calif);
}

void list_insert(struct NODO **head,int n)
{
	struct NODO *new;
	struct NODO *ptr;
	
	new=malloc(sizeof(struct NODO));
	new->num=n;
	new->next=NULL;

	if(*head==NULL)	// No hay nada en la lista
		*head=new;
	else
	{
		ptr=*head;
		while(ptr->next){
            if (ptr->next!=NULL) //Este IF es para poder checar el ultimo numero de la lista
            {
                if (ptr->num > new->num)
                {
                    int cache = ptr->num;
                    ptr->num = new->num;
                    new->num = cache;
                }
            }
            else //Para que cheque tambien el ultimo numero
            {
                if (ptr->num > new->num)
                {
                    int cache = ptr->num;
                    ptr->num = new->num;
                    new->num = cache;
                }
            }
            ptr = ptr->next;
        }
        ptr->next=new;
        //Necesario por alguna razon
        if (ptr->next->num < ptr->num){
            int cache = ptr->num;
            ptr->num = ptr->next->num;
            ptr->next->num = cache;
        }
	}
}


void list_display(struct NODO *ptr, int *n,int *e)
{
	int prev=-1;
	int cont=0;
	int err=0;
	while(ptr!=NULL)
	{
		if(ptr->num<prev)
			err++;
		printf("%d\n",ptr->num);
		prev=ptr->num;
		ptr=ptr->next;
		cont++;
	}	
	*n=cont;
	*e=err;
}
