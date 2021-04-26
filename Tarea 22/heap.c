#include "heap.h"
#include <stdio.h>

void insert(struct STRBH *bh,int n){
	bh->arr[bh->size]=n;
	bh->size++;
}

void insert_complete(struct STRBH *bh, int data, int index){
    int a = 0;
    if(index%2 != 0)
        a = index/2;
    else
        a = (index/2)-1;

    if(bh->arr[a] > data && index != 0){
        bh->arr[index] = bh->arr[a];
        insert_complete(bh, data, a);
    }
    else{
        bh->arr[index] = data;
        bh->size++;
    }
}

void recorre(struct STRBH *bh,int elem,int spaces){
	int i;
	if(elem < bh->size){
		for(i=0;i<spaces;i++)
			printf("\t");
		printf("%d\n",bh->arr[elem]);

		recorre(bh,left(elem),spaces+1);

		recorre(bh,right(elem),spaces+1);

	}
}

BH bh_create(int maxsize){
	BH tmp=malloc(sizeof(struct STRBH));
	tmp->arr=malloc(maxsize*sizeof(int));
	tmp->size=0;
	return(tmp);
}
