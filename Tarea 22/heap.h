#include <stdlib.h>

#ifndef heap_h_

struct STRBH {
	int *arr;
	int size;
};

typedef struct STRBH* BH;

void insert(struct STRBH *bh,int n);
void insert_complete(struct STRBH *bh, int data, int index);
void recorre(struct STRBH *bh,int elem,int spaces);
BH bh_create(int maxsize);

#define left(n) (n*2+1)
#define right(n) (n*2+2)

#endif // set_h_
