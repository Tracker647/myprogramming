#include <stdio.h>
#include <string.h>
int main()
{
    char *str, *p1, *p2;
    int i, len, flag = 1;
    printf("输入字符串\n");
    scanf("%s", str);
    printf("字符串:%s\n", str);
    len = strlen(str);
    printf("字符长度:%d\n", len);
    for (i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
            flag = 0;
    }
    if (flag)
        printf("%s是回文\n", str);
    else
        printf("%s不是回文\n", str);
    
    return 0;
}