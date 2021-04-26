#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define LIST_INITIALIZER {NULL,NULL}

typedef struct STRNODO {
	int num;
	struct STRNODO *next;
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
    NODO *ptr = l->head;
	NODO *new=malloc(sizeof(NODO));
	new->num=num;
	new->next=ptr;

	if(l->head==NULL)
		l->head=new;
	else
		l->tail->next=new;
	l->tail=new;

	return;
}

void list_display(LIST l, int n)
{
	NODO *ptr=l.head;
	int i = 0;
	while(i < n)
	{
        printf("%d\n",ptr->num);
        ptr=ptr->next;
        i++;
	}
}

int main()
{
	int inicio,fin,n;
	int i,count=0;
	int tiempo;
	LIST lista1=LIST_INITIALIZER;
	clock_t tinicio,tfin;

	setbuf(stdout,NULL);

	printf("Valor inicial :");
	scanf("%d",&inicio);
	printf("Valor final :");
	scanf("%d",&fin);
	printf("Cuantas veces:");
	scanf("%d", &n);

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
	list_display(lista1,n);
}
