#include <stdio.h>
int main()
{
    int i, a;
    a = 2;
    for (i = 9; i >= 1; i--)
        a = (a + 2) * 2;
    printf("��һ��ժ�µ�������Ϊ:%d\n", a);
}