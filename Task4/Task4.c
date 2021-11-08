#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

char* strcpy (const char* src)
{
    int size = 0, i = 0;
    while (src[size]) size++;
    char* res = (char*)malloc((size + 1) * sizeof(char));
    while (src)
    {
        if (src[i] != '\0') {
            res[i] = src[i];
        }
        else {
            res[i] = '\0';
            return res;
        }
        i++;
    }
}

void main()
{
    char* res = (char*)malloc(sizeof(char));
    const char a[20] = "qweertyuvfjyjlczaxn";
    printf("%s\n", a);
    res = strcpy(&a);
    printf("%s", res);
    free(res);
}