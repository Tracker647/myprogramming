#include <stdio.h>
int main()
{
    int count = 0;
    inc(&count);
    printf("%d", count);
}
int inc(int *c)
{
    (*c) = (*c) + 1; //注意*c要括号，否则就变成了指向下一个地址
    return *c;
}