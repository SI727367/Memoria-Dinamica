#include <stdlib.h>
#include <stdbool.h>

#ifndef stack_h_
typedef void* TYPE;
typedef int* BOOL;

struct STRNODE {
	TYPE data;
	struct STRNODE *prev;
};

typedef struct STRNODE* NODE;

struct STRSTACK {
	NODE top;
	int size;
};

typedef struct STRSTACK* STACK;

STACK stack_create();
void stack_push(STACK s,TYPE e);
TYPE stack_pop(STACK s);
void stack_push_int(STACK stack,int num);
int stack_pop_int(STACK stack);
TYPE stack_top(STACK stack);
void stack_destroy(STACK stack);
BOOL stack_isempty(STACK stack);
int stack_size(STACK stack);
#endif
