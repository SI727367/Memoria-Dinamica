#include <stdio.h>
#include <string.h>

typedef void* TYPE;

long long myhash(TYPE data);

int main()
{
	char cad[20];

	setbuf(stdout,NULL);

	do {
		printf("Dame una llave ");
		scanf("%s",cad);
		printf("El código generado es : %I64x\n",myhash(cad));
	} while(strcmp(cad,"FIN")!=0);
}

long long myhash(TYPE data)
{
	int suma=0;
	int factm=1;
	char *cad=data;
	while(*cad) {
		suma=suma+(*cad * factm);
		cad++;
		factm=factm*2;
	}
	return(suma);
}


