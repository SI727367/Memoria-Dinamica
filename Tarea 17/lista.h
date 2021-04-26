#include <stdlib.h>

#ifndef lista_h_
typedef void* TYPE;

struct STRNODE {
	TYPE data;
	struct STRNODE *prior,*next;
};

typedef struct STRNODE* NODE;
typedef NODE ITERATOR;

struct STRLIST {
	NODE first,last,prefirst,postlast;
	int size;
};

typedef struct STRLIST* LIST;

LIST list_create();
void list_insert_int(LIST list,int n);
void list_insert(LIST list,TYPE data);
TYPE list_remove(LIST list, int i);
ITERATOR list_get(LIST list, int i);
void list_set(LIST list, TYPE element, int i);
#define list_begin(l) (l->prefirst)
#define has_next(i) (i->next)
#define iterator_data(i) (*((int *) i->data))
#define list_next(i) (i->next)
#define list_end(l) (l->postlast)
#define has_prior(i) (i->prior)
#define list_prior(i) (i->prior)
#endif
