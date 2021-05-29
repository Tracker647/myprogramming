#include     <stdio.h>
#include     <stdlib.h>
#include    <string.h>

void factorial(int n, char *pout)
{
    if (pout == NULL)
    {
        return;
    }

    int arr[256];
    int idx = 1;
    arr[0] = 1;
    //此处要注意　i从１开始
    for (int i = 1; i <= n; i++)
    {
        //cry用来记录进位
        int cry = 0;
        // idx记录现在有多少位　挨个相乘
        for (int j = 0; j < idx; j++)
        {
            arr[j] = arr[j] * i + cry;
            //此处用倒序存储
            cry = arr[j] / 10;
            arr[j] %= 10;
        }
        //如果进位大于１０　要降级
        while (cry > 10)
        {
            arr[idx++] = cry % 10;
            cry /= 10;
        }
        //进位到这里如果还大于　０　证明位数要加１
        if (cry > 0)
            arr[idx++] = cry;
    }
    //将数组倒序赋值给字符串
    for (int i = idx - 1; i >= 0; i--)
    {
        *pout++ = arr[i] + '0';
    }
    *pout = '\0';
    return;
}

int main()
{
    char buff[255] = {0};
    int n = 0;
    printf("input n:");
    scanf("%d", &n);
    factorial(n, buff);
    puts(buff);
    return 0;
}