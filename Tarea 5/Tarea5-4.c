#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#define SIZE 1000
#define NTHREADS 16
float PI = 1.0, k = 3;
int i;
CRITICAL_SECTION cs;

DWORD WINAPI tfunc(LPVOID args)
{
	int mynum=*((int *) args);
	int inicio=mynum*(SIZE/NTHREADS);
	int fin=(mynum+1)*(SIZE/NTHREADS);
	printf("Hilo %d, inicio=%d, fin=%d\n",mynum,inicio,fin);
    
    for (i = inicio; i < fin; i++){
		float cache = 1/k;
        EnterCriticalSection(&cs);
		if (i % 2 == 0){
            PI -= cache;
        }
        if (i % 2 == 1){
            PI += cache;
        }
		LeaveCriticalSection(&cs);
        k = k + 2;
        //printf("%f\n",4*PI);
		printf("%f\n",cache);
    }
	return 0;
}

int main()
{
	int i;
	int tiempo;
	clock_t inicio,fin;
	HANDLE tid[NTHREADS];
	int params[NTHREADS];

	inicio=clock();
	InitializeCriticalSection(&cs);
	for(i=0;i<NTHREADS;i++)
	{
		params[i]=i;
		tid[i]=CreateThread(NULL,0,tfunc,&params[i],0,NULL);
	}
	WaitForMultipleObjects(NTHREADS,tid,1,INFINITE);
	DeleteCriticalSection(&cs);
	
	fin=clock();
	tiempo=((int) fin - (int) inicio)/1000;
	printf("El tiempo fue %d segundos\n",tiempo);
	printf("El valor Pi es %f",4*PI);
}