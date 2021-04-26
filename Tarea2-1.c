#include <stdio.h>

void swap(char *pa,char *pb){
	int c = 0;
	c = *pa;
	*pa = *pb;
	*pb = c;
}

void reverse(char *pstring1){
    int n = 0;
	while (1){
		if (*(pstring1+n) != '\0'){
			n++;
		}
		else{
			break;
		}
	}
    char *pstring2 = pstring1 + n - 1;

    while (pstring1 < pstring2) { 
        swap(pstring1 , pstring2); 
        pstring1++; 
        pstring2--; 
    }
}

int main(){

    char string1[] = "Guadalajara";

    reverse(string1);
    printf("%s\n", string1);
}