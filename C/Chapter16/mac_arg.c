#include<stdio.h>
#define SQUARE(X) ((x)*(x))
#define PR(x) printf("The result is %d.\n",x)
int main(void)
{
    int x=5;
    int z;

    printf("x = %d\n",x);

    z = SQUARE(x);
    printf("Evaluating SQUARE(x):");
    PR(z);

    z= SQUARE(x+2);
    printf("Evaluating SQUARE(x+2):");
    PR(z);

    printf("Evaluating 100/SQUARE(2):");
    printf(100/SQUARE(2));

    printf("x is %d.\n",x);
    printf("Evaluating SQUARE£¨++x):");
    PR(SQUARE(++x));
    printf("After incrementing,x is %x.\n",x);

    return 0;

}