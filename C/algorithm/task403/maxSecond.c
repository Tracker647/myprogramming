#include <stdio.h>
int maxSecond(int lmax1, int lmax2, int rmax1, int rmax2, int *fmax1, int *fmax2);
int main()
{
    int lmax1 = 7, lmax2 = 3, rmax1 = 9, rmax2 = 5;
    int fmax1, fmax2;
    maxSecond(lmax1, lmax2, rmax1, rmax2, &fmax1, &fmax2);
    printf("fmax1=%d fmax2=%d\n", fmax1, fmax2);
}
int maxSecond(int lmax1, int lmax2, int rmax1, int rmax2, int *fmax1, int *fmax2)
{
    if (lmax1 < rmax1)
    {
        if (rmax1 > lmax2)
        {
            *fmax1 = rmax1;
            *fmax2 = lmax1;
        }
        else
        {
            *fmax1 = rmax1;
            *fmax2 = lmax2;
        }
    }
    else
    {
        if (lmax2 > rmax1)
        {
            *fmax1 = lmax1;
            *fmax2 = lmax2;
        }
        else
        {
            *fmax1 = lmax1;
            *fmax2 = rmax1;
        }
    }
}