/*
效果:运行程序，程序要求用户输入二进制数的字符串，程序获取字符串后若检查成功则
返回十进制的int结果，并可让用户重复此过程

步骤：
定义字符数组以储存要输入的字符串
输入并让程序接受字符串
程序将字符串传给输入检查函数，输入检查函数处理后在传给二进制检查函数{1}
通过二进制检查函数的字符串传给转换函数{2}处理后输出十进制结果

{1}:接受字符串后遍历字符串，初始化布尔值为binary=true用于标识字符串是否为符合数
异常情况为数不为0或者1
遍历过程中若发现异常情况则将binary置为false，报错并中止程序；
若遍历完毕后无异常情况，则将数返回给主函数

{2}:接受字符串后遍历字符串，提取出二进制数的位数（strlen(st)）
从第一位开始乘上对应的幂计算十进制，算法为：
    rel=rel+2^(len-i)*st++

循环化：
*/
#include<stdio.h>
#include<stdbool.h>
#include <string.h>
#include<limits.h>
#include<math.h>
#define size CHAR_BIT * sizeof(int) + 1
char* s_gets(char* st,int n);
char* bcheck(char* st);
int trans(char *st);
int main()
{
    char pbin[size];
    int rel;
    int i;
    printf("input binary number for transform,empty line to quit:\n");

    while(s_gets(pbin,size) && pbin[0]!='\0')
    {   
        // printf("Your number:");
        // for(i=0;pbin[size]!='\0';i++)
        // {
        //     printf("%c",pbin[i]);
        // }
        // printf("\n");

        bcheck(pbin);
        rel = trans(pbin);
        printf("The value is:%d\n",rel);
        printf("input next number:\n");
        
    }
    puts("Done.");
    return 0;
}

char* s_gets(char* st,int n)
{
    char* ret_val;
    char* find;
    ret_val=fgets(st,n,stdin);
    if(ret_val)
    {
        find = strchr(st,'\n'); //查找输入的字符串在前n个字的范围内是否有换行符
        if(find)
            *find = '\0';   //若有将尾部的换行符替代掉
        else
            while(getchar()!='\n')  //若无将n后面的字符全部丢弃
                continue;       
    }
    return ret_val;
}

char* bcheck(char* st)
{
    bool binary = true;
    while(*st!='\0')
    {
        if(*st!='0'&&*st!='1')
        {
            binary = false;
            printf("%s is not a binary!",st);
            break;
        }
        *st++;
    }
    return st;
}
int trans(char* st) //二转十
{
    int val=0,i=1;
    int len = strlen(st);
    while(*st!=0)
    {   
        val=val+pow(2,len-i)*((int)*st-48);
        i++;
        *st++;
    }
    return val;
}





































