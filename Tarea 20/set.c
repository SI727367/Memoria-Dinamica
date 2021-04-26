#include <stdio.h>
#include "set.h"

TREE tree_create(){
    TREE tmp = malloc(sizeof(struct STRTREE));
    tmp->root = NULL;
    tmp->size = 0;
    return(tmp);
}

void tree_insert(TREE tree,int n){
    NODE new = malloc(sizeof(struct STRNODE));
    NODE ptr = tree->root;
    NODE buff = NULL;
    SIDE side;
    new->num = n;
    new->left = NULL;
    new->right = NULL;

    if(tree->root == NULL){
        tree->root = new;
    }else{
        while(ptr!=NULL)
		{
			buff=ptr;
			if(new->num < ptr->num)
			{
				side=LEFT;
				ptr=ptr->left;
			}
			else if(new->num > ptr->num)
			{
				side=RIGHT;
				ptr=ptr->right;
			}
			else
			{
				side=NONE;
				ptr=NULL;
				free(new);
			}
		}
		if(side == LEFT){
            buff->left = new;
		}else if (side == RIGHT){
            buff->right = new;
		}
    }
    tree->size++;
}

void inorden(NODE node){
    if(node!=NULL)
	{
		inorden(node->left);
		printf("%d\n",node->num);
		inorden(node->right);
	}
}
