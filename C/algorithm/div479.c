#include <stdio.h>
int main()
{
    int n;
    printf("��������:\n");
    scanf("%d", &n);
    if ((n % 4) && (n % 7) && (n % 9))
        printf("%d���ܱ�4,7,9��һ������\n",n);
    else
    {
        if (n % 4 ==0)
            printf("%d�ܱ�4����\n",n);
        if (n % 7 ==0)
            printf("%d�ܱ�7����\n",n);
        if (n % 9 ==0)
            printf("%d�ܱ�9����\n",n);
    }
}