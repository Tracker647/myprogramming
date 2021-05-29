#include <stdio.h>
#include <math.h>
#define PR(X,...) printf("Message:"#X":"__VA_ARGS__)

int main()
{
    double x = 48;
    double y;

    y = sqrt(x);
    PR(1,"x=%g\n",x);
    PR(2,"X=%.2f,y= %.4f\n",x,y);

    return 0;

}