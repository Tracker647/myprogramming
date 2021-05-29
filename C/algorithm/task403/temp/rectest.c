#include <stdio.h>
int lmin = 0;
int main()
{
    int min = 0;
    rectest(&min);
    printf("%d\n", lmin);
}
rectest(int *fmin)
{

    if (*fmin < 5)
    {
        (*fmin)++;
        rectest(&lmin);
    }
}