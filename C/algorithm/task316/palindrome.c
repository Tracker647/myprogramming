#include <stdio.h>
#include <string.h>
int main()
{
    char *str, *p1, *p2;
    int i, len, flag = 1;
    printf("�����ַ���\n");
    scanf("%s", str);
    printf("�ַ���:%s\n", str);
    len = strlen(str);
    printf("�ַ�����:%d\n", len);
    for (i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
            flag = 0;
    }
    if (flag)
        printf("%s�ǻ���\n", str);
    else
        printf("%s���ǻ���\n", str);
    
    return 0;
}