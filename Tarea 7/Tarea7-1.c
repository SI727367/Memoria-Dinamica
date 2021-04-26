#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <time.h>

#define NTHREADS 16
#define TASKSIZE 100

int inicio,fin;
int count=0;
unsigned int ctask = 0;

CRITICAL_SECTION cs1;
CRITICAL_SECTION cs2;

int esprimo(int n)
{
	int primo=0;
	int factor=3;
	int limite=sqrt(n);

	if(n<2)
		primo=0;
	else if(n==2)
		primo=1;
	else if(n%2==0)	// es un par mayor a 4
		primo=0;
	else
	{
		while(factor<=limite && n%factor)
			factor+=2;

		primo=factor>limite;
	}
	return(primo);
}

DWORD WINAPI tfunc(LPVOID arg)
{
	int tnum=*((int *)arg);
	int tinicio,tfin;
	int i;
	int lcount=0;
	int task;
	int ntasks=1+(fin-inicio)/TASKSIZE;

	//printf("Hilo %d desde %d hasta %d\n",tnum,tinicio,tfin);

	EnterCriticalSection(&cs2);
	task = ctask;
	ctask++;
	LeaveCriticalSection(&cs2);

	while(task<ntasks){
		tinicio=inicio+task*TASKSIZE;
		tfin=tinicio+TASKSIZE-1;
		if(tfin>fin)
			tfin=fin;
		// printf("Hilo=%d, Tarea=%d, Inicio=%d, Fin=%d\n",tnum,task,tinicio,tfin);
		for(i=tinicio;i<=tfin;i++)
			if(esprimo(i))
				lcount++;

        EnterCriticalSection(&cs2);
        task = ctask;
        ctask++;
        LeaveCriticalSection(&cs2);
	}

	EnterCriticalSection(&cs1);
	count+=lcount;
	LeaveCriticalSection(&cs1);
	return 0;
}

int main()
{
	int i;
	float tiempo;
	clock_t tinicio,tfin;
	HANDLE tid[NTHREADS];
	int params[NTHREADS];

	setbuf(stdout,NULL);

	printf("Valor inicial: ");
	scanf("%d",&inicio);
	printf("Valor final: ");
	scanf("%d",&fin);

	tinicio=clock();

	InitializeCriticalSection(&cs1);
    InitializeCriticalSection(&cs2);
	for(i=0;i<NTHREADS;i++)
	{
		params[i]=i;
		tid[i]=CreateThread(NULL,0,tfunc,&params[i],0,NULL);
	}

	WaitForMultipleObjects(NTHREADS,tid,1,INFINITE);
	DeleteCriticalSection(&cs1);
	DeleteCriticalSection(&cs2);

	tfin=clock();
	tiempo=((int) tfin -(int) tinicio)/1000.0;
	printf("\n%d primos encontrados entre %d y %d\n",count,inicio,fin);
	printf("Tiempo = %.3f seg\n",tiempo);

}
