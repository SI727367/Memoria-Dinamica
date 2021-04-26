#include <stdlib.h>

#ifndef set_h_

typedef enum {NONE,LEFT,RIGHT} SIDE;

typedef void* TYPE;

struct STRNODE {
	TYPE data;
	struct STRNODE *left;
	struct STRNODE *right;
};

typedef struct STRNODE* NODE;

typedef int (*COMPAREFUNC) (TYPE,TYPE);
typedef void (*PRINTFUNC) (TYPE);
typedef void (*DESTRUCTFUNC) (TYPE);

struct STRSET {
	NODE root;
	int size;
	COMPAREFUNC comparefunc;
	PRINTFUNC printfunc;
	DESTRUCTFUNC destructfunc;
};

typedef struct STRSET* SET;

void set_print(SET set);
void set_destroy(SET set);
void t_print(NODE node,PRINTFUNC pf,int spaces);
SET set_create(COMPAREFUNC cf,PRINTFUNC pf,DESTRUCTFUNC df);
void set_insert(SET set,TYPE data);
int set_size(SET set);
void t_destroy(NODE node,DESTRUCTFUNC df);

#endif // set_h_
