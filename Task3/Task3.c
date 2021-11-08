#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int find(const char* str, const char* substr)
{
    int i = 0;
    while (str)
    {
        const char* s = str;
        const char* sbs = substr;
        while (*s == *sbs)
        {
            s++; sbs++;
            if (*sbs == '\0' || *s == '\0')
                break;
        }
        if (*sbs == '\0')
            return i;
        if (*s == '\0')
            return 0;
        str++;
        i++;
    }
    return 0;
}

char *delete (const char* str, const char* substr)
{
    int sbsize = 0, ssize = -1, pos = find(str,substr), i = 0;
    while (substr[sbsize]) sbsize++;
    while (str[ssize]) ssize++;
    char* res = (char*)malloc((ssize - sbsize + 1) * sizeof(char));
    while (i <= ssize)
    {
        if (ssize - sbsize > i) {
            if (i < pos) res[i] = str[i];
            else res[i] = str[i+sbsize];
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
    const char substr[6] = "lczax", a[20]="qweertyuvfjyjlczaxn";
    printf("%s %s\n", substr, a);
    res = delete(&a, &substr);
    printf("%s", res);
    free(res);
}