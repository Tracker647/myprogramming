#include <stdio.h>
int main()
{
    int i, a;
    a = 2;
    for (i = 9; i >= 1; i--)
        a = (a + 2) * 2;
    printf("第一天摘下的桃子数为:%d\n", a);
}