#include <stdlib.h>


#ifndef queues_h_
typedef void* TYPE;

struct STRNODE {
	TYPE data;
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
#endif
