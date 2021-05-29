#include <stdio.h>
int main()
{
    int n;
    printf("输入整数:\n");
    scanf("%d", &n);
    if ((n % 4) && (n % 7) && (n % 9))
        printf("%d不能被4,7,9任一个整除\n",n);
    else
    {
        if (n % 4 ==0)
            printf("%d能被4整除\n",n);
        if (n % 7 ==0)
            printf("%d能被7整除\n",n);
        if (n % 9 ==0)
            printf("%d能被9整除\n",n);
    }
}