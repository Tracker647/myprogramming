#include <stdio.h>
void intToArray(int i, int *arr);
int main()
{
    int a[4] = {0}, b[3] = {0}, c[5] = {0}, d[5] = {0}, s[6] = {0}, allfac;
    int *p[5] = {a, b, c, d, s}; //��ָ������ָ��5�����������飬���Ժ����
    int i, j, a1, b1, s1, c1, d1;
    for (i = 222; i <= 777; i++)
    {

        for (j = 22; j <= 77; j++)
        {
            allfac = 1;
            a1 = i;
            b1 = j;
            intToArray(a1, a);
            intToArray(b1, b);
            s1 = a1 * b1;   //������
            c1 = a1 * b[0]; //����ĵ�һ������
            d1 = a1 * b[1]; //����ĵڶ�������

            //���õ����������������黯
            intToArray(c1, c);
            intToArray(d1, d);
            intToArray(s1, s);
            int tempi = i;
            int tempj = j;
            //�жϳ˷�������Ƿ�ȫ������
            for (i = 0; i <= 5; i++)
            {
                for (j = 0; p[i][j] != -1; j++) //����ָ�������ϵ�ÿ������
                {
                    if (!(p[i][j] == 2 || p[i][j] == 3 || p[i][j] == 5 || p[i][j] == 7))
                    {
                        allfac = 0;
                    }
                }
            }
            i = tempi;
            j = tempj;
            if (allfac)
            {
                break;
            }
            else
            {
                printf("����������,Ŀǰ:%d x %d\n", a1, b1);
            }
        }
    }
    printf("���������ĳ˷�����:\n");
    printf("   %d\n", a1);
    printf("x\n");
    printf("   %d\n", b1);
    printf("______\n");
    printf(" %d\n", c1);
    printf("%d\n", d1);
    printf("%d\n", s1);
}
void intToArray(int i, int *arr)
{
    int stack[10];
    int rem, j = 0, k = 0;
    while (i != 0)
    {
        rem = i % 10;
        i = i / 10;
        stack[k++] = rem;
    }
    for (i = k - 1; i >= 0; i--)
    {
        arr[j++] = stack[i];
    }
    arr[j] = -1;
}