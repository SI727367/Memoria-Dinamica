#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contenedor.c"

void str_empty(char word[50]);
void str_simplify(unsigned char *c);

int main(){
    //abrir archivo
    FILE *txt = fopen("texto.txt", "r");
    //identificar palabras
    char word[50] = "";
    int n = 0;
    char ch = 0;

    int i, pos;
    LIST lista[M];
    NODE tmp;
    for(i=0;i<M;i++)
		lista[i]=list_create();

    do{
        ch = fgetc(txt);
        while(ch != ' ' && ch != EOF && ch != '\n'){
            word[n] = ch;
            n++;
            ch = fgetc(txt);
        }
        //contar palabras
        str_simplify(word);
        pos = hash(word) % M;
        //printf("%s \t %d \n", word, pos);
        list_insert(lista[pos],word);
        n = 0;
        str_empty(word);
    }while(ch != EOF);
    //mostrar palabras
    int result = 0;
    for(i=0; i<M ;i++){
        tmp = lista[i]->first;
        while(tmp != NULL){
            result++;
            printf("%d. %s \n",result, tmp->value);
            tmp = tmp->next;
        }
    }

    printf("\n~~~ El total de palabras diferentes es: %d ~~~\n", result);

    fclose(txt);

    return 0;
}

void str_empty(char word[50]){
    int i = 0;
    while(word[i] != '\0'){
        word[i] = 0;
        i++;
    }
}

void str_simplify(unsigned char *c){
    while(*c != '\0'){
        if(*c >= 65 && *c <=90){
            *c += 32;
        }else{
            switch(*c){
                case 159:
                case 221:
                case 253:
                case 255:
                    *c = 121;
                    break;
                case 193:
                case 196:
                case 225:
                case 228:
                    *c = 97;
                    break;
                case 201:
                case 203:
                case 233:
                case 235:
                    *c = 101;
                    break;
                case 205:
                case 207:
                case 237:
                case 239:
                    *c = 105;
                    break;
                case 211:
                case 214:
                case 243:
                case 246:
                    *c = 111;
                    break;
                case 218:
                case 220:
                case 250:
                case 252:
                    *c = 117;
                    break;
                default:
                    break;

            }
        }
        if(*c < 'a' || *c > 'z')
            *c = 'z';
        c++;
    }
}
