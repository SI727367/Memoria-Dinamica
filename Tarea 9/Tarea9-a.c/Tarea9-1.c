#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printmat(int **m,int r);

int main()
{
	int ren,col;
	int i,j;
	int **matriz;
	srand ( time(NULL));
	int ko = rand() ;
	ren = (ko % 20)+1;
	printf("R = %d\n",ren);

	col = ren;
	matriz=malloc(ren*sizeof(int *));

	for(i=0;i<=ren;i++){
		matriz[i]=malloc((col)*sizeof(int));
	}

	for(i=0;i<ren;i++){
		for(j=0;j<i+1;j++){
			matriz[i][j]=i+1;
		}
	}
	printmat(matriz,ren);

    return 0;
}

void printmat(int **m,int r)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<i+1;j++)
			printf("%d\t",m[i][j]);
		printf("\n");
	}
}