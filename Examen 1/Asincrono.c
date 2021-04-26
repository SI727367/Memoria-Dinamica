#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int i, j;
time_t t;
char ex;

int dia = 0;
int enf, sal, rec;

typedef struct{
    short   id;
    short   edad;
    char    status;
    short   dias;
    bool    usaCB;
    bool    getSick
}PERSONA;

typedef struct{
    bool disp;
    PERSONA persona;
}celda;
celda tab[50][50];

void printTab(){
    //GENERA REPORTE
    for(i=0; i<50 ;i++){
        for(j=0; j<50 ;j++){
            if((*(*(tab+i)+j)).persona.status == 'S' ||
               (*(*(tab+i)+j)).persona.status == 's')
                sal++;
            if((*(*(tab+i)+j)).persona.status == 'E' ||
               (*(*(tab+i)+j)).persona.status == 'e')
                enf++;
            if((*(*(tab+i)+j)).persona.status == 'R')
                rec++;
        }
    }
    //IMPRIME TABLERO
    printf("\n");
    for(i=0; i<50 ;i++){
        for(j=0; j<50 ;j++){
            printf("%c ", (*(*(tab+i)+j)).persona.status);
            (*(*(tab+i)+j)).persona.getSick = false;
        }
        printf("\n");
    }
    //IMPRIME REPORTE
    printf("~~~REPORTE DIA %d~~~\n", dia);
    printf("Sanos:  \t%d \n", sal);
    printf("Enfermos: \t%d \n", enf);
    printf("Recuperados: \t%d \n", rec);
    //RESET
    dia++;
    enf = 0;
    sal = 0;
    rec = 0;
}

bool vecino(int a, int b, bool CB){
    int por = 0;
    if(((*(*(tab+a)+b)).persona.status == 'E' || (*(*(tab+a)+b)).persona.status == 'e') &&
       ((*(*(tab+a)+b)).persona.usaCB && CB)){
        por = 6;
    }
    else if(((*(*(tab+a)+b)).persona.status == 'E' || (*(*(tab+a)+b)).persona.status == 'e') &&
            ((*(*(tab+a)+b)).persona.usaCB || CB)){
        por = 20;
    }
    else if((*(*(tab+a)+b)).persona.status == 'E' || (*(*(tab+a)+b)).persona.status == 'e'){
        por = 60;
    }
    if(rand()%100 < por){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    bool stop;

    //PORCENTAJE DE POBLACION
    int porc;
    int id = 1;
    printf("Ingrese el porcetaje (0-100) del tablero que quiere con poblacion: ");
    scanf("%d", &porc);
    //GENERA TABLERO
    srand((unsigned) time(&t));
    for(i=0; i<50 ;i++){
        for(j=0; j<50 ;j++){
            if(rand()%100 < porc){
                (*(*(tab+i)+j)).disp = false;
                if(rand()%2 == 0){
                    (*(*(tab+i)+j)).persona.usaCB = true;
                }
                else{
                    (*(*(tab+i)+j)).persona.usaCB = false;
                }
                if((*(*(tab+i)+j)).persona.usaCB){
                    (*(*(tab+i)+j)).persona.status = 's';
                }
                else{
                    (*(*(tab+i)+j)).persona.status = 'S';
                }
                (*(*(tab+i)+j)).persona.id = id;
                id++;
            }
            else{
                (*(*(tab+i)+j)).disp = true;
            }
            (*(*(tab+i)+j)).persona.dias = 0;
            (*(*(tab+i)+j)).persona.getSick = false;
        }
    }
    //GENERA PACIENTE 0
    int x = rand()%50;
    int y = rand()%50;
    (*(*(tab+x)+y)).persona.status = 'E';
    (*(*(tab+x)+y)).persona.usaCB = false;
    (*(*(tab+x)+y)).persona.id = 0;
    (*(*(tab+x)+y)).disp = false;
    printTab();
    //LOOP
    while(1){
        //EXIT
        printf("Presiona ENTER para continuar o escribe X para salir\n");
        scanf("%c", &ex);
        if(ex == 'x' || ex == 'X'){
            return 0;
        }
        //SUMA DIAS
        for(i=0; i<50 ;i++)
            for(j=0; j<50 ;j++)
                if((*(*(tab+i)+j)).persona.status == 'E' ||
                   (*(*(tab+i)+j)).persona.status == 'e')
                    (*(*(tab+i)+j)).persona.dias++;
        //CHECA TABLERO
        for(i=0; i<50 ;i++){
            for(j=0; j<50 ;j++){
                if(!(*(*(tab+i)+j)).disp){
                    //arriba
                    if(i-1>=0 && j-1>=0)
                        if(vecino(i-1,j-1,(*(*(tab+i)+j)).persona.usaCB))
                            (*(*(tab+i)+j)).persona.getSick = true;
                    if(i-1>=0)
                        if(vecino(i-1,j,(*(*(tab+i)+j)).persona.usaCB))
                            (*(*(tab+i)+j)).persona.getSick = true;
                    if(i-1>=0 && j+1<50)
                        if(vecino(i-1,j+1,(*(*(tab+i)+j)).persona.usaCB))
                            (*(*(tab+i)+j)).persona.getSick = true;
                    //medio
                    if(j-1>=0)
                        if(vecino(i,j-1,(*(*(tab+i)+j)).persona.usaCB))
                            (*(*(tab+i)+j)).persona.getSick = true;
                    if(j+1<50)
                        if(vecino(i,j+1,(*(*(tab+i)+j)).persona.usaCB))
                            (*(*(tab+i)+j)).persona.getSick = true;
                    //abajo
                    if(i+1<50 && j-1>=0)
                        if(vecino(i+1,j-1,(*(*(tab+i)+j)).persona.usaCB))
                            (*(*(tab+i)+j)).persona.getSick = true;
                    if(i+1<50)
                        if(vecino(i+1,j,(*(*(tab+i)+j)).persona.usaCB))
                            (*(*(tab+i)+j)).persona.getSick = true;
                    if(i+1<50 && j+1<50)
                        if(vecino(i+1,j+1,(*(*(tab+i)+j)).persona.usaCB))
                            (*(*(tab+i)+j)).persona.getSick = true;
                }
            }
        }
        //CAMBIA TABLERO
        for(i=0; i<50 ;i++){
            for(j=0; j<50 ;j++){
                if((*(*(tab+i)+j)).persona.getSick &&
                  ((*(*(tab+i)+j)).persona.status != 's' ||
                   (*(*(tab+i)+j)).persona.status != 'S')){
                    if((*(*(tab+i)+j)).persona.usaCB){
                        (*(*(tab+i)+j)).persona.status = 'e';
                    }
                    else{
                        (*(*(tab+i)+j)).persona.status = 'E';
                    }
                }
                if((*(*(tab+i)+j)).persona.dias >= 7)
                    (*(*(tab+i)+j)).persona.status = 'R';
            }
        }
        //IMPRIME TABLERO
        printTab();
    }
    return 0;
}
