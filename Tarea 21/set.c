#include <stdio.h>
#include "set.h"

SET set_create(COMPAREFUNC cf,PRINTFUNC pf,DESTRUCTFUNC df)
{
	SET tmp=malloc(sizeof(struct STRSET));
	tmp->comparefunc=cf;
	tmp->printfunc=pf;
	tmp->destructfunc=df;
	tmp->root=NULL;
	tmp->size=0;
	return(tmp);
}

void set_destroy(SET set)
{
	t_destroy(set->root,set->destructfunc);
	free(set);
	set=NULL;
}

void t_destroy(NODE node,DESTRUCTFUNC df)
{
	if(node->left!=NULL)
		t_destroy(node->left,df);

	if(node->right!=NULL)
		t_destroy(node->right,df);

	df(node->data);
	free(node);
}

void set_insert(SET set,TYPE data)
{
	NODE new=malloc(sizeof(struct STRNODE));
	NODE prev=NULL;
	NODE ptr=set->root;
	SIDE side;
	new->data=data;
	new->left=NULL;
	new->right=NULL;


	// No hay nada en el бrbol
	if(set->root==NULL)
	{
		set->root=new;
		// printf("Root %d\n",n);
	}
	else
	{
		while(ptr!=NULL)
		{
			prev=ptr;
			if(set->comparefunc(data,ptr->data)<0) // Nos vamos por la izquierda
			{
				side=LEFT;
				ptr=ptr->left;
			}
			else if(set->comparefunc(data,ptr->data)>0) // Nos vamos por la derecha
			{
				side=RIGHT;
				ptr=ptr->right;
			}
			else // Si el elemento ya estб en el бrbol
			{
				side=NONE;	// No se va a insertar en ningъn lado
				ptr=NULL;	// ptr le asignamos NULL para salir del while
				free(new);	// Liberamos la memoria del nodo que ibamos a insertar
			}
		}
		if(side==LEFT)
		{
			prev->left=new;
			set->size++;
		}
		if(side==RIGHT)
		{
			prev->right=new;
			set->size++;
		}
	}
}

int set_size(SET set)
{
	return(set->size);
}

void set_print(SET set)
{
	t_print(set->root,set->printfunc,0);
}

void t_print(NODE node,PRINTFUNC pf,int spaces)
{
	int i;


	if(node->left!=NULL)
		t_print(node->left,pf,spaces+1);

	for(i=0;i<spaces;i++)
			printf(" ");
	pf(node->data);


	if(node->right!=NULL)
		t_print(node->right,pf,spaces+1);

}
