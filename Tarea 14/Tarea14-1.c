#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define LIST_INITIALIZER {NULL,NULL}

typedef struct STRNODO {
	int num;
	struct STRNODO *next;
	struct STRNODO *prev;
} NODO;

typedef struct {
	struct STRNODO *head;
	struct STRNODO *tail;
} LIST;

unsigned int factores=0;

int esprimo(int n)
{
	int primo=0;
	int factor=3;
	int limite=sqrt(n);

	if(n<2)
		primo=0;
	else if(n==2)
		primo=1;
	else if(n%2==0)	// es un par mayor a 4
		primo=0;
	else
	{
		factores++;
		while(factor<=limite && n%factor)
		{
			factor+=2;
			factores++;
		}

		primo=factor>limite;
	}
	return(primo);
}

void list_insert(LIST *l,int num)
{
	NODO *new=malloc(sizeof(NODO));
	new->num=num;
	new->next=NULL;
	new->prev=l->tail;

	if(l->head==NULL)
		l->head=new;
	else
		l->tail->next=new;
	l->tail=new;

	return;
}

void list_display(LIST l)
{
    int orden;
    printf("Ascendente(1) o descendente(0)? (1/0) :");
    scanf("%d", &orden);

    NODO *ptr;
    if(orden==1){
        ptr=l.head;
    }
    else if(orden==0){
        ptr=l.tail;
    }
	while(ptr!=NULL){
		printf("%d\n",ptr->num);

		if(orden==1){
            ptr=ptr->next;
        }
        else if(orden==0){
            ptr=ptr->prev;
        }
	}
}

int main()
{
	int inicio,fin;
	int i,count=0;
	int tiempo;
	LIST lista1=LIST_INITIALIZER;
	clock_t tinicio,tfin;

	setbuf(stdout,NULL);

	printf("Valor inicial :");
	scanf("%d",&inicio);
	printf("Valor final :");
	scanf("%d",&fin);

	tinicio=clock();
	for(i=inicio;i<=fin;i++)
		if(esprimo(i))
		{
			count++;
			list_insert(&lista1,i);
		}
	tfin=clock();
	tiempo=((int) tfin -(int) tinicio)/1000;
	printf("%d primos encontrados entre %d y %d\n",count,inicio,fin);
	printf("Factores=%d\n",factores);
	printf("Tiempo = %d segundos\n",tiempo);
	list_display(lista1);
}
