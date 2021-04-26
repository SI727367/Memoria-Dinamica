#include <stdio.h>

typedef struct strdate {
    int year;
    int month;
    int day;
    struct strdate *next;
} DATE;

void printdates(DATE *d);
void print3dates(DATE d);
void insert(DATE **ptrinciolista,DATE *n);

int main()
{
    DATE d1={1,10,2019,NULL};
    DATE d2={2,02,2020,NULL};
    DATE d3={3,03,2021,NULL};

    DATE *iniciolista=NULL;

    insert(&iniciolista,&d1);
    insert(&iniciolista,&d2);
    insert(&iniciolista,&d3);

    printdates(iniciolista);
}

void insert(DATE **ptriniciolista,DATE *n)
{
    if (*ptriniciolista == NULL)
    {
        *ptriniciolista = n;
    }
    else
    {
        DATE *ptr=*ptriniciolista;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next = n;
    }
}

void printdates(DATE *d)
{
   DATE *ptr=d;

   while(ptr!=NULL)
   {
       printf("%d,%d,%d\n",ptr->year,ptr->month,ptr->day);
       ptr=ptr->next;
   }
}