#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#define NTHREADS 16
#define LEN 5
#define ITER ((int) pow(62,LEN))
#define RESULT 0xBDC96A4

int countcad=0;
CRITICAL_SECTION cs;

char cod(char c)
{
	char ret;
	if(c>=0 && c<=9)
		ret='0'+c;
	else if(c>=10 && c<=35)
		ret='A'+c-10;
	else if(c>=36 && c<=61)
		ret='a'+c-36;
	else
		ret=0;
	return(ret);
}

unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

     while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

     return hash;
}

void strgen(char *s,int n)
{
	int i;
        s[LEN]='\0';
	for(i=LEN-1;i>=0;i--)
	{
		s[i]=cod(n%62);
		n/=62;
	}
}

DWORD WINAPI tfunc(LPVOID args)
{
	int mynum=*((int *) args);
	int inicio=mynum*(ITER/NTHREADS);
	int fin=(mynum+1)*(ITER/NTHREADS);
	printf("Hilo %d, inicio=%d, fin=%d\n",mynum,inicio,fin);
    int k = 0, i = 0;
    char cad[LEN+1];
    for (i = inicio; i < fin; i++){
		strgen(cad,i);
		if(hash(cad)==RESULT)
		{
			printf("La cadena encontrada es %s\n",cad);
            k++;
		}
    }
	EnterCriticalSection(&cs);
    countcad+= k;
    LeaveCriticalSection(&cs);
    return 0;
}

int main()
{
	int i;
	float tiempo;
	clock_t tinicio,tfin;
	HANDLE tid[NTHREADS];
	int params[NTHREADS];

	tinicio=clock();
	InitializeCriticalSection(&cs);
	for(i=0;i<NTHREADS;i++)
	{
		params[i]=i;
		tid[i]=CreateThread(NULL,0,tfunc,&params[i],0,NULL);
	}
	WaitForMultipleObjects(NTHREADS,tid,1,INFINITE);
	DeleteCriticalSection(&cs);
	
	tfin=clock();
	tiempo=((int) tfin - (int) tinicio)/1000;
	printf("\nEl tiempo fue %.5f segundos\n",tiempo);
    printf("Soluciones encontradas %d\n",countcad);
}