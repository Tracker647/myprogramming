#include <stdio.h>
#include <stdlib.h>
int numlen(int s)
{
    int count;
    while(s>1)
    {
        s = s/10;
        count++;
    }
    printf("������%dλ\n",count);

    return count;
}
int* InitArr(int s,int len)
{
    int *arr = (int)malloc(sizeof(int)*len);
    int i;
    for(i=len;i>0;i--)
    {
        s = s/10;
        arr[i] = s % 10;
    }
    return arr;
}
int main()
{
    int i, n = 7;
    int s = n;
    int len;
    int *arr ;
    for (i = 7; i > 1; i--)
    {
        s = s * (i - 1);
    }
    printf("%d!=%d\n", n, s);

    len = numlen(s);
    arr = InitArr(s, len);
    for (i = len; i > 0; i--)
    {
        if (arr[i] != 0)
        {
            printf("���ұߵķ�0����Ϊ:%d\n",arr[i]);
            break;
        }
    }
    return 0;
}

