#include <stdio.h>
int main()
{
    int n, i = 0, rem, stack[5], count[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int flag1 = 0, flag2 = 0;
    int temp;
    printf("输入数n:\n");
    scanf("%d", &n);
    temp = n;
    while (n != 0)
    {
        rem = n % 10;
        n = n / 10;
        stack[i] = rem;
        i++;
        if (i > 3)
        {
            printf("输入有误，必须是3位\n");
            for (i = 0; i < 5; i++)
            {
                stack[i] = 0;
            }
            printf("输入数n:\n");
            scanf("%d", &n);
        }
    }
    n = temp;
    for (i = 0; i < 2; i++)
        count[stack[i]]++; //统计n中各位0-9的出现次数
    for (i = 0; i < 9; i++)
    {
        if (count[i] == 2)
        {
            flag1 = 1; //符合条件1:两位数字相同
        }
    }
    for (i = 10; i < 31; i++) //数的范围在100-961
    {
        if (i * i == n)
        {
            flag2 = 1; //符合条件2:完全平方数
        }
    }
    if (flag1 & flag2)
    {
        printf("%d是满足条件的整数\n", n);
    }
    else
    {
        printf("%d不是满足条件的整数\n", n);
    }
}