#include <stdio.h>
#include <stdlib.h>
#define H 20
struct STRNODE {
	int key,value;
	struct STRNODE* next;
};

typedef struct STRNODE* NODE;

struct STRLIST {
	NODE first,last;
	int size;
};


typedef struct STRLIST* LIST;

LIST list_create();
void list_insert(LIST list,int data);
long hash(int data);
int findMode(int nums[], int n);
int main()
{
  int cn,N;

  printf("Cantidad de numeros: ");
  scanf("%d",&cn);
  int lista[cn];

  for(int i = 0; i<cn; i++)
  {
    printf("Numero %d: ", i+1);
    scanf("%d",&N);
    lista[i] = N;
  }
  for(int i = 0; i<cn; i++)
  {
    printf("%d\n",lista[i]);
  }
  printf("La moda de la lista es: %d\n",findMode(lista, cn));
}
int findMode(int nums[], int n)
{
    int i,hashcode,pos;
    LIST lista[H];
    NODE Resultado = NULL;
    NODE tmp;
    for(i=0;i<H;i++)
		lista[i]=list_create();
    for (i=0;i<n;i++)
    {
        hashcode=hash(nums[i]);
		pos=hashcode % H;
		list_insert(lista[pos],nums[i]);
    }
    for(i=0;i<H;i++)
    {
        tmp = lista[i]->first;
        while(tmp!=NULL)
        {
            if(Resultado == NULL)
                Resultado = tmp;
            if(Resultado->value < tmp->value)
                Resultado = tmp;
            tmp = tmp->next;
        }
    }
    return(Resultado->key);
}
long hash(int data)
{
	int suma=data;
	suma *= 2;
    suma = suma * suma;
    suma +=1;
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

void list_insert(LIST list,int data)
{
    NODE new = malloc(sizeof(struct STRNODE));
    new->key = data;
    new->next = NULL;
    new->value = 1;
    NODE tmp;

    if(list->first==NULL)
    {
        list->first = new;
        list->size++;
    } else
    {
        tmp = list->first;
        while (tmp !=NULL){
            if(tmp->key == data)
            {
                tmp->value++;
                return;
            }
            tmp = tmp->next;
        }
        list->last->next=new;
        list->size++;
    }
    list->last = new;

}