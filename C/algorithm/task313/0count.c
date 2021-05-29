#include <stdio.h>
int main()
{
    int s = 1, i = 0, j, idx = 1, cry;
    int n, rem, stack[256] = {1};
    long double count = 0;
    char str[10000];
    printf("输入n的值:\n");
    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        cry = 0;
        for (j = 0; j < idx; j++)
        {
            stack[j] = stack[j] * i + cry; //用阶乘数乘以当前运算的每一位
            cry = stack[j] / 10;
            stack[j] = stack[j] % 10;
        }

        if (cry > 10) //进位大于10时要降级
        {
            stack[idx++] = cry % 10;
            cry = cry / 10;
        }
        if (cry > 0) //如果计算结果出现了进位,则新的位值是进位值
        {
            stack[idx++] = cry;
        }
    }
    i = 0;
    printf("结果为:\n");
    for (j = idx - 1; j >= 0; j--)
    {
        printf("%d", stack[j]);
        if (stack[j] == 0)
            count++;
    }
    printf("\n");
    printf("n!的末尾有%ld个0", count);
}