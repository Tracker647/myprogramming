#define _INTTOARRAY_H_
#ifndef _INTTOARRAY_H_
int intToArray(int n, int *arr)
{
    int stack[5] = {-1};
    int rem;
    int len = 0, i = 0, j;
    int temp = n;
    while (n != 0)
    {
        rem = n % 10;
        n = n / 10;
        stack[len++] = rem;
    }
    printf("%d is %d-digit\n", temp, len);
    for (int j = len - 1; j >= 0; j--)
    {
        arr[j] = stack[i++];
    }
    return len;
}

long longToArray(long n, long *arr) //将Long数组转化为整数
{
    long stack[5] = {-1};
    long rem;
    int len = 0, i = 0, j;
    long temp = n;
    while (n != 0)
    {
        rem = n % 10;
        n = n / 10;
        stack[len++] = rem;
    }
    printf("%d是%d位数\n", temp, len);
    for (int j = len - 1; j >= 0; j--)
    {
        arr[j] = stack[i++];
    }
    return len;
}

int hasRepInArray(long *arr) //整数数组中是否有重复数字
{
    int digit;
    int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < longArrLen(arr); i++)
    {
        digit = arr[i];
        count[digit]++;
    }
    for (int j = 0; j < 10; j++)
    {
        if (count[j] > 1)
            return 1;
    }
    return 0;
}
int longArrLen(long *arr) //测量数组长度
{
    int count = 0;
    for (int i = 0; arr[i] != '\000'; i++)
        count++;
    // printf("%d\n", count);
    return count;
}
#endif