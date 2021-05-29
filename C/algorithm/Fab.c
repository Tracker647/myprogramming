#include <stdio.h>
#include <math.h>
int stack = 0;
int depth = 0;
int fac(int n);
int main()
{
    int n, s;
    printf("Fibonacci:");
    scanf("%d", &n);
    s = fac(n);
    printf("f(n) = %d \n", n, s);
    printf("栈调用次数:%d \n", stack);
    depth = log2(stack + 1);
    printf("栈调用深度:%d \n", depth);
}
int fac(int n)
{
    int s;
    stack++;
    if (n <= 0)
    {
        s = 0;
    }
    if (n <= 2 && n > 0) //f(1) = 1,f(2)=2;
    {
        s = n;
    }
    else
    {
        s = fac(n - 2) + fac(n - 1);
    }
    if (stack == 1)
    {
        printf("%d ", s);
    }

    return s;
}