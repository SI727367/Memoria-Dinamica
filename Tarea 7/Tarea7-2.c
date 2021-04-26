#include <stdio.h>
#include <time.h>
#include <math.h>

int i,j;

int numeros_amigos(int x){
    int sumax = 0,sumay = 0,y = 0;
	for (i = 1; i < x; i++){
		if (x%i==0)
			sumax+=i;
	}
	y = sumax;
	for (j = 1; j < y; j++){
		if (y%j==0)
			sumay+=j;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
	}
	
	if ((sumax == y) && (x == sumay) && (x != y))
		printf ("%d %d\n",sumax,sumay);
}   

int main(){
	float tiempo;
    int inicio,fin,tinicio,tfin;
    printf("Valor inicial: ");
	scanf("%d",&inicio);
	printf("Valor final: ");
	scanf("%d",&fin);
	
	tinicio=clock();

    for (i = inicio; i <= fin; i++)
		numeros_amigos(i);

	tfin=clock();
	tiempo=((int) tfin -(int) tinicio)/1000.0;
	printf("Tiempo = %.4f seg\n",tiempo);
}