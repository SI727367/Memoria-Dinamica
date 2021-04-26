#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    const char **pa = a;
    const char **pb = b;
    return strcmp(*pa, *pb);
}

int main(void)
{
    char *nombres[] = {"Juán","José","Gaby","María","Karla","Luis","Antonio","Cecilia","Roberto","Francisdo"};
    size_t len = sizeof nombres / sizeof nombres[0];
    qsort(nombres, len, sizeof nombres[0], cmp);

    for(size_t i = 0; i < len; i++) {
        printf("%s\n", nombres[i]);
    }
    return 0;
}