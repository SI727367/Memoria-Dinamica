#include <stdio.h>
#include <math.h>

int lenght(char *pyeet){
	int i = 0;
	while (1){
		if (*(pyeet+i) != '\0'){
			i++;
		}
		else{
			break;
		}
	}
	return i;
}

void swap(int *pa,int *pb){
	int c = 0;
	c = *pa;
	*pa = *pb;
	*pb = c;
}

void toUnit(float *parray){

	float *parray2 = parray++;
	float modulo = sqrtf(powf(*parray,2)+powf(*parray2,2));
	
	*parray = *parray / modulo;
	*parray2 = *parray2 / modulo;
}

int main (){
	
	char Yeet[]="Hola mundo";
	printf("La longitud es: %d\n",lenght(Yeet));

	int a = 35,b = 40;
	swap(&a,&b);
	printf("a=%d,b=%d\n",a,b);

	float V []= {3,4};
	toUnit(V);
	printf("%f,%f\n",V[0],V[1]);
}