#include <stdio.h>
#include <stdlib.h>
typedef struct work
{
    int p;
    int d;
    int flag;
} work;

int cmp(work x, work y)
{
    if (x.flag == y.flag)
    {
        if (x.flag == 0)
            return x.p > y.p;
        return x.d < y.d;
    }
    return x.flag > y.flag;
}
int main()
{
    work J[6];
    int print[6] = {3, 12, 5, 2, 9, 11};
    int deco[6] = {8, 10, 9, 6, 3, 1};
    int i;
    for (i = 0; i < 6; i++)
    {
        J[i].p = print[i];
        J[i].d = deco[i];
        J[i].flag = J[i].p < J[i].d ? 0 : 1;
    }
    qsort(J, 6, sizeof(J[0]), cmp);
    for (i = 0; i < 6; i++)
    {
        printf("%5d ", J[i].p);
    }
    printf("\n");
    for (i = 0; i < 6; i++)
    {
        printf("%5d ", J[i].d);
    }
    printf("\n");
    int time = 0;
    printf("time=");
    for (i = 0; i < 6; i++)
    {
        time += J[i].p;
        printf(" %d + ", J[i].p);
    }
    time += J[5].d;
    printf(" %d ", J[i].d);

    printf("\n");
    printf("%d\n", time);
}
