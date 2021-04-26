#include <stdlib.h>

#ifndef set_h_

typedef enum {NONE,LEFT,RIGHT} SIDE;

struct STRNODE {
	int num;
	struct STRNODE *left;
	struct STRNODE *right;
};

typedef struct STRNODE* NODE;

struct STRTREE {
    NODE root;
    int size;
};

typedef struct STRTREE* TREE;

TREE tree_create();
void tree_insert(TREE tree,int n);
void inorden(NODE node);

#endif // set_h_
