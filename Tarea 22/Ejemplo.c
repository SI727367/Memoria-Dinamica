#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap.c"

int main(){
    srand(time(0));
	BH bh = bh_create(127);

	int i, n;
	for(i=0; i<127 ;i++){
        n=rand()%100;
		insert_complete(bh,n,bh->size);
	}

	recorre(bh,0,0);

    return 0;
}
