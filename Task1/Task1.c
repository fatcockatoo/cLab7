#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void incrementHeapVariable()
{
    int* c = (int*)malloc(sizeof(int));
    scanf_s("%d", &c[0]);
    printf("%hx %d", &c, c[0]);
    c[0]++;
    printf("\n%hx %d", &c, c[0]);
    free(c);
}
void main()
{
    incrementHeapVariable();
}