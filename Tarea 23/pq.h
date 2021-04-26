
typedef void * TYPE;
typedef int (*COMPAREFUNC) (TYPE,TYPE);
typedef void (*PRINTFUNC) (TYPE);

struct STRPQ {
	TYPE *arr;
	int size_of_data;
	int size;
	COMPAREFUNC comparefunc;
	PRINTFUNC printfunc;
};

typedef struct STRPQ* PQ;

void pq_offer(struct STRPQ *pq,TYPE data);
void pq_display(PQ PQ);
void recorre(struct STRPQ *pq,int elem,int spaces,PRINTFUNC printfunc);
PQ pq_create(int maxsize,PRINTFUNC printfunc,COMPAREFUNC comparefunc,int size_of_data);
int compare(TYPE d1,TYPE d2);
void swap(TYPE d1,TYPE d2,int size);
void print(TYPE d);
TYPE pq_poll(PQ pq);