#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#define SIZE 1000000
#define NTHREADS 16
int g = 0;

DWORD WINAPI tfunc(LPVOID args)
{
	int mynum=*((int *) args);
	int inicio=mynum*(SIZE/NTHREADS);
	int fin=(mynum+1)*(SIZE/NTHREADS);
	int i;
	printf("Hilo %d, inicio=%d, fin=%d\n",mynum,inicio,fin);

	for (i = inicio; i <= fin; i++){
        bool Primo = true;
        int k = 2;
		if (i < 2){
			Primo = false;
		}

        while (k <= i){
			if ((i % k == 0 && k != i) && k < i/2){
				Primo = false;
				break;
			}
			k++;
		}

		if (Primo == true){
			printf("%d\n",i);
			g++;
		}
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

	for(i=0;i<NTHREADS;i++)
	{
		params[i]=i;
		tid[i]=CreateThread(NULL,0,tfunc,&params[i],0,NULL);
	}

	WaitForMultipleObjects(NTHREADS,tid,1,INFINITE);
	fin=clock();
	tiempo=((int) fin - (int) inicio)/1000;
	printf("El tiempo fue %d segundos\n",tiempo);
	printf("La cantidad de numeros primos entre %d y %d es %d\n",inicio,SIZE,g);
}