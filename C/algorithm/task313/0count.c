#include <stdio.h>
int main()
{
    int s = 1, i = 0, j, idx = 1, cry;
    int n, rem, stack[256] = {1};
    long double count = 0;
    char str[10000];
    printf("����n��ֵ:\n");
    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        cry = 0;
        for (j = 0; j < idx; j++)
        {
            stack[j] = stack[j] * i + cry; //�ý׳������Ե�ǰ�����ÿһλ
            cry = stack[j] / 10;
            stack[j] = stack[j] % 10;
        }

        if (cry > 10) //��λ����10ʱҪ����
        {
            stack[idx++] = cry % 10;
            cry = cry / 10;
        }
        if (cry > 0) //��������������˽�λ,���µ�λֵ�ǽ�λֵ
        {
            stack[idx++] = cry;
        }
    }
    i = 0;
    printf("���Ϊ:\n");
    for (j = idx - 1; j >= 0; j--)
    {
        printf("%d", stack[j]);
        if (stack[j] == 0)
            count++;
    }
    printf("\n");
    printf("n!��ĩβ��%ld��0", count);
}