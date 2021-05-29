#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *str1;
    char str2[10];
    printf("输入字符串1:");
    scanf("%s",str1); 
    printf("输入字符串2:");
    scanf("%s",str2); 

    printf("字符串1:%s 字符串2:%s\n",str1,str2);
}