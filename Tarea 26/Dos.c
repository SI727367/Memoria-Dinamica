#include <stdlib.h>
#include <stdio.h>

void processTasks (int d[], int N);

int main()
{

int durations[] = {5, 2, 3, 1, 4}; // duraciones de las tareas = {A, B, C, D, E}

processTasks(durations, 5);

}


void processTasks (int d[], int N)
{
  
  for( int i = 0; i < N; i++ )
  {

    for( int j = 0; j < 5; j++ ) //preguntar si el 5 esta asegurado
    {

      if( d[j] > 0 )
      {
        printf("%c ", 65 + j);
        d[j] --;
      } 

    }
    
    
  }
  
}