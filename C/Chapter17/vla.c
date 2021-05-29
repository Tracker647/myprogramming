#include<stdio.h>

const int n = 3;

void gaussin(double a[n][n], double b[n])
{
    //�ж��ܷ��ø�˹��Ԫ��������������Խ�������0Ԫ�ش����ǲ����õ�
    for (int i = 0; i < n; i++)
        if (a[i][i] == 0)
        {
           printf("can't use gaussin meathod.\n"); 
           return 0;
        }

    int i, j, k;
    double c[n];    //�洢�����б任��ϵ���������е����
    //��Ԫ�������������£��ܹ�n-1����Ԫ���̡�
    for (k = 0; k < n - 1; k++)
    {
        //�����K�γ����б任��ϵ��
        for (i = k + 1; i < n; i++)
            c[i] = a[i][k] / a[k][k];

        //��K�ε���Ԫ����
        for (i = k + 1; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                a[i][j] = a[i][j] - c[i] * a[k][j];
            }
            b[i] = b[i] - c[i] * b[k];
        }
    }

//��Ĵ洢����
    double x[n];
    //�ȼ�������һ��δ֪����
    x[n - 1] = b[n - 1] / a[n - 1][n - 1];
    //���ÿ��δ֪����ֵ
    for (i = n - 2; i >= 0; i--)
    {
        double sum = 0;
        for (j = i + 1; j < n; j++)
        {
            sum += a[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / a[i][i];
    }

    printf("the solution of the equations is:");
    printf("\n");
    for (i = 0; i < n; i++)     
        printf("%d", x[i]); 

}