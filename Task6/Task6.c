#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

char* insert(const char* src, const char* str, int index)
{
    int sscr = 0, sstr = 0;
    while (src[sscr]) sscr++;
    while (str[sstr]) sstr++;
    char* res = (char*)malloc((sscr + sstr+1) * sizeof(char));
    for (int i = 0; i < sscr + sstr; i++) {
        if (i <= index)
            res[i] = src[i];
        else if (i > index + sstr) {
            res[i] = src[i - sstr];
        }
        else {
            res[i] = str[i - index - 1];
        }
    }
    res[sscr + sstr] = '\0';
    return res;
}

void main()
{
    int n = 4;
    char* res = (char*)malloc(sizeof(char));
    const char a[20] = "qweertyuvfjyjlczaxn", b[10] = "fzgbzfdhg";
    printf("%s %s\n", a, b);
    res = insert(&a, &b, n);
    printf("%s", res);
    free(res);
}