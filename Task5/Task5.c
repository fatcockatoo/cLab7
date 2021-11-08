#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

char* strcat(const char* first, const char* second)
{
    int sfirst = 0, ssecond = 0;
    while (first[sfirst]) sfirst++;
    while (second[ssecond]) ssecond++;
    char* res = (char*)malloc((sfirst + ssecond + 1) * sizeof(char));
    for (int i = 0; i <= sfirst + ssecond; i++) {
        if (i < sfirst) res[i] = first[i];
        else if (i >= sfirst && i < sfirst + ssecond) res[i] = second[i - sfirst];
        else { 
            res[i] = '\0';
            return res;
        }
    }

}

void main()
{
    char* res = (char*)malloc(sizeof(char));
    const char a[20] = "qweertyuvfjyjlczaxn", b[10]="fzgbzfdhg";
    printf("%s %s\n", a, b);
    res = strcat(&a,&b);
    printf("%s", res);
    free(res);
}