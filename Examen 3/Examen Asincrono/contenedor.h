#ifndef contenedor_h

#include <stdlib.h>
#define M 100

struct STRNODE {
	char value[50];
	struct STRNODE* next;
};

typedef struct STRNODE* NODE;

struct STRLIST {
	NODE first,last;
	int size;
};

typedef struct STRLIST* LIST;

LIST list_create();
void list_insert(LIST list,char data[50]);
long hash(char data[50]);

#endif
