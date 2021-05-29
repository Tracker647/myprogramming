#include<stdio.h>
#define N 4
int main()
{
    float x[N]={1,3,4,6},y[N]={2,4,8,22};
    float m,s,a;
    int i,j;
    m=2.5;
    s=0;
    for(i=0;i<N;i++)
    {
        a=1;
        for(j=0;j<N;j++)
            if(i!=j)
                a=a*(m-x[j])/(x[i]-x[j]);
        s=s+a*y[i];
    }
    printf("\n");
    printf("the result is:\n%15.11f\n",s);
}