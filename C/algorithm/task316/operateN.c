#include <stdio.h>
int main()
{
    int i, n, len, arr[5];
    printf("����n:\n");
    scanf("%d", &n);
    len = intToArray(n, arr);
    printf("˳��:");
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("����:");
    for (i = len - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
}
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
    printf("%d��%dλ��\n", temp, len);
    for (int j = len - 1; j >= 0; j--)
    {
        arr[j] = stack[i++];
    }
    return len;
}