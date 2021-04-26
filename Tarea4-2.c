#include <stdio.h>

void arrtolower(char words[][10], int n){
    int i;
    char *pword = (char *) words;
    char *pwordc = (char *) words;
    for(i = 0; i < n; i++){
        pword = pwordc;
        while(*pword != '\0'){
            if(*pword >= 65 && *pword <= 90){
                *pword+= 32;
            }
            printf("%c", *pword);
            pword++;
        }
        printf("\n");
        pwordc += 10;
    }

}
int main(){
    char words[][10] = {"HOLA", "MUNDO", "Cruel5", "ADIoS"};
    arrtolower(words, 4);
}
