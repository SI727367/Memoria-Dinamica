#include <stdio.h>
#include <stdlib.h>


struct STRNODE {
	int value;
	struct STRNODE* next;
};

typedef struct STRNODE* NODE;

struct STRLIST {
	NODE first,last;
	int size;
};


typedef struct STRLIST* LIST;


LIST list_create();
int list_insert(LIST list,int data);
long hash(int data);
int containsDuplicate (int nums[], int n);

int containsDuplicate (int nums[], int n)
{
    int hashcode,position,result;
    LIST list[n];
    for(size_t i=0;i<n;i++)
		list[i]=list_create();
    for (size_t i=0;i<n+3;i++)
    {
        hashcode=hash(nums[i]);
		position=hashcode % n;
		result = list_insert(list[position],nums[i]);
        if(result == 1)
            return 1;
    }
    return 0;
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

int list_insert(LIST list,int data)
{
    NODE new = malloc(sizeof(struct STRNODE));
    new->value = data;
    new->next = NULL;
    NODE tmp;

    if(list->first==NULL)
    {
        list->first = new;
        list->size++;
    } else
    {
        tmp = list->first;
        while (tmp !=NULL){
            if(tmp->value == data)
            {
                return (1);
            }
            tmp = tmp->next;
        }
        list->last->next=new;
        list->size++;
    }
    list->last = new;
    return 0;

}
int main()
{
  int cn,N,resultado;
  
  printf("Cantidad de numeros: ");
  scanf("%d",&cn);
  int lista[cn];

  for(int i = 0; i<cn; i++)
  {
    printf("Numero %d: ", i+1);
    scanf("%d",&N);
    lista[i] = N;
  }
  /*for(int i = 0; i<cn; i++)
  {
    printf("%d\n",lista[i]);
  }*/

  printf("¿La lista contiene numeros duplicados?\n");
  resultado = containsDuplicate(lista,cn);
  if (resultado == 1)
      printf("True ");
  else
      printf("False ");
  return 0;
}
