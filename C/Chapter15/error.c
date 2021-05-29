#include<stdio.h>
#include<limits.h>
#define SIZE 30

char* itobs(int n,char * ps)    //十进制转二进制
{
    int i;
    const static int size = CHAR_BIT*sizeof(int);

    for(i=size-1;i>=0;i--,n>>=1)
    {
        ps[i] = (01 & n)+'0';
    }
    ps[size] = '\0';

    return ps;
}

int main()
{
    char pbin[SIZE];
    int d;
    printf("input dec number:\n");
    scanf("%d",&d);
    itobs(d,pbin);
    printf("Now the bin number:%s\n",pbin);
    return 0;
}


























