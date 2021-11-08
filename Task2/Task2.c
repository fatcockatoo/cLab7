#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void sortHeapArray(int *arr, int n)
{
    int t, m;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand()%20;
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        m = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[m])
                m = j;
        }
        t = arr[i];
        arr[i] = arr[m];
        arr[m] = t;
        printf("%d ", arr[i]);
    }
}
void main()
{
    int* a;
    int n;
    scanf_s("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    printf("%d \n", n); 
    sortHeapArray(a,n);
    free(a);
}