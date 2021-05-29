#include <stdio.h>
int main()
{
    int flag, i, sum;
    int arr[4] = {0};

    printf("number follows rules:\n");
    for (i = 1000; i <= 9999; i++)
    {
        flag = 1;

        intToArray(i, arr);
        flag = isRepeat(arr);
        if (arr[0] == 0)
            flag = 0;
        sum = digitSum(arr);
        if (i % (sum * sum) != 0)
            flag = 0;
        if (flag)
            printf("%d ", i);
        else
            printf("%d is not required number\n", i);
    }
}
int intToArray(int i, int *arr)
{
    int rem, k;
    int stack[4];
    int len = 0;
    while (i != 0)
    {
        rem = i % 10;
        i = i / 10;
        stack[k++] = rem;
    }
    len = k;
    k = 0;
    for (i = len - 1; i >= 0; i--)
    {
        arr[k++] = stack[i];
    }
}

int isRepeat(int *arr)
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = i + 1; j <= 3; j++)
        {
            if (arr[i] == arr[j])
            {
                return 0;
            }
        }
    }
}

int digitSum(int *arr)
{
    int i, sum = 0;
    for (i = 0; i < 4; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}
