#include <stdio.h>
int main()
{
    int n, i = 0, rem, stack[5], count[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int flag1 = 0, flag2 = 0;
    int temp;
    printf("������n:\n");
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
            printf("�������󣬱�����3λ\n");
            for (i = 0; i < 5; i++)
            {
                stack[i] = 0;
            }
            printf("������n:\n");
            scanf("%d", &n);
        }
    }
    n = temp;
    for (i = 0; i < 2; i++)
        count[stack[i]]++; //ͳ��n�и�λ0-9�ĳ��ִ���
    for (i = 0; i < 9; i++)
    {
        if (count[i] == 2)
        {
            flag1 = 1; //��������1:��λ������ͬ
        }
    }
    for (i = 10; i < 31; i++) //���ķ�Χ��100-961
    {
        if (i * i == n)
        {
            flag2 = 1; //��������2:��ȫƽ����
        }
    }
    if (flag1 & flag2)
    {
        printf("%d����������������\n", n);
    }
    else
    {
        printf("%d������������������\n", n);
    }
}