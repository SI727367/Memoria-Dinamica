#include <stdio.h>
#include "arbol.h"

void tree_insert(SET c1,int n)
{
	NODE new=malloc(sizeof(struct STRNODE));
	NODE prev=NULL;
	SIDE side;
	NODE ptr = c1->root;
	new->num=n;
	new->left=NULL;
	new->right=NULL;


	// No hay nada en el árbol
	if(c1->root == NULL)
	{
		c1->root=new;
		// printf("Root %d\n",n);
	}
	else
	{
		while(ptr!=NULL)
		{
			prev=ptr;
			if(new->num < ptr->num) // Nos vamos por la izquierda
			{
				side=LEFT;
				ptr=ptr->left;
			}
			else if(new->num > ptr->num) // Nos vamos por la derecha
			{
				side=RIGHT;
				ptr=ptr->right;
			}
			else // Si el elemento ya está en el árbol
			{
				side=NONE;	// No se va a insertar en ningún lado
				ptr=NULL;	// ptr le asignamos NULL para salir del while
				free(new);	// Liberamos la memoria del nodo que ibamos a insertar
			}
		}
		if(side==LEFT)
		{
			prev->left=new;
		}
		if(side==RIGHT)
		{
			prev->right=new;
		}
	}
}

void inorden(NODE node)
{
	if(node!=NULL)
	{
		inorden(node->left);
		printf("%d\n",node->num);
		inorden(node->right);
	}
}

SET create_set()
{
    SET tmp = malloc(sizeof(struct STRSET));
    /* tmp->compare_func = cf;
    tmp->destructor = destroy;
	  tmp->print_func = pf; */
    tmp->size = 0;
    tmp->root = NULL;
    return tmp; 
}


int sumGreaterThan( NODE root, int compareInt )
{
  int back = 0;

  if(root->num > compareInt)
  {
    back+=root->num;
    if(root->right)
      back+=sumGreaterThan(root->right,compareInt);
    if(root->left)
      back+=sumGreaterThan(root->left,compareInt); 
  }
  else
  {
    if(root->right)
      back+=sumGreaterThan(root->right,compareInt);
  }

  return back;
}