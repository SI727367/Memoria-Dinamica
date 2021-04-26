#include <stdlib.h>


#ifndef tdaespecial_h_
typedef void* TYPE;

struct STRNODESTACK {
	TYPE data;
	struct STRNODESTACK *prev;
};

typedef struct STRNODESTACK* NODESTACK;

struct STRSTACK {
	NODESTACK top;
	int size;
};

typedef struct STRSTACK* STACK;

struct STRNODE {
    STACK Qstack;
	struct STRNODE *next;
};

typedef struct STRNODE* NODE;

struct STRQUEUE {
	NODE first;
	NODE last;
	int size;
};

typedef struct STRQUEUE* QUEUE;

QUEUE queue_create();
void queue_offer(QUEUE queue,TYPE element);
TYPE queue_poll(QUEUE queue);

STACK stack_create();
void stack_push(STACK s,TYPE e);
TYPE stack_pop(STACK s);
void stack_push_int(STACK stack,int num);
int stack_pop_int(STACK stack);
#endif
