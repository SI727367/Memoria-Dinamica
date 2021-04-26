#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid (char s[]);
typedef void* TYPE;

struct STRNODE {
	TYPE data;
	struct STRNODE *prev;
};

typedef struct STRNODE* NODE;

struct STRSTACK {
	NODE top;
	int size;
};

typedef struct STRSTACK* STACK;

STACK stack_create();
void stack_push(STACK s,TYPE e);
TYPE stack_pop(STACK s);

TYPE stack_top(STACK stack);

void stack_destroy(STACK stack);

int main()
{
  setbuf(stdout, NULL);
  char cadena[50]; 
  printf("Cadena de caracteres: ");
  scanf("%s",cadena);
  
  if (isValid(cadena))
    printf("La cadena es valida");
  else
    printf("La cadena no es valida");

}

bool isValid( char s[] )
{

  STACK stringStack = stack_create();
  
  for( size_t i = 0; s[i] != '\0'; i++  )
  {
    
    if( s[i] == '[' || s[i] == '(' || s[i] == '{'  )
    {
      stack_push(stringStack, (TYPE)(&s[i]));

    } else if( s[i] == ']' || s[i] == ')' || s[i] == '}' )
    {
      char* current = (char*)(stack_top(stringStack));
    

      if( (*current == '(' && s[i] == ')') || (*current == '[' && s[i] == ']') || (*current == '{' && s[i] == '}') )
      {
        stack_pop(stringStack);
      } else
      {
        //printf("No es valido \n");
        return false;
      }

      
    } else {
      //printf("No es valido \n");
      return false;
    }

  }
  printf("Es valido \n");
  return true;
  
}

STACK stack_create()
{
	STACK tmp=malloc(sizeof(struct STRSTACK));
	tmp->top=NULL;
	tmp->size=0;
	return(tmp);
}


void stack_push(STACK stack,TYPE element)
{
	NODE new=malloc(sizeof(struct STRNODE));
	new->data=element;
	new->prev=stack->top;	// El previo al nodo apunta a donde estaba
					// antes el tope
	stack->top=new;
    stack->size++;
}


TYPE stack_pop(STACK stack)
{
	NODE to_erase=stack->top;
	TYPE data=to_erase->data;
	stack->top=to_erase->prev;	// El tope, apunta al elemento previo.
	stack->size--;
    free(to_erase);
	return(data);
}

TYPE stack_top(STACK stack)
{
    TYPE data = stack->top->data;
    return(data);
}


void stack_destroy(STACK stack)
{
    while(stack->size > 0)
    {
        NODE to_erase=stack->top;
        stack->top=to_erase->prev;
        stack->size--;
        free(to_erase);
    }
}
