#include <stdlib.h>

#define min 15
#define max 20

typedef void* TYPE;

typedef enum {NONE,LEFT,RIGHT} SIDE;

typedef void (*DESTROYFUNC) (int);
typedef void (*PRINTFUNC) (int);
typedef void (*COMPAREFUNC) (int);

struct STRNODE
{
	int num;
	struct STRNODE *left;
	struct STRNODE *right;
};
typedef struct STRNODE* NODE;

struct STRSET
{
    NODE root;
    int size;
	/*COMPAREFUNC compare_func;
	DESTROYFUNC destructor;
	PRINTFUNC	print_func;*/
};
typedef struct STRSET* SET;

SET create_set();
void tree_insert(SET c1,int n);
void inorden(NODE node);
int sumGreaterThan( NODE root, int compareInt );