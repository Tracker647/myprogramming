/*实验效果：运行程序,程序要求输入两个字符串,输入后返回
两个字符串经过“~,&,|,^”运算后的二进制值

伪代码：
定义字符数组bin1,bin2,bin3存储两个二进制数，定义整数v1,v2存储两个十进制数;

向bin1 bin2输入要运算的二进制数,输入结果须通过bcheck(){1}函数检验;

由于位运算符的参数都是十进制数，需要bstr_to_dec(){2}函数将两字符转化为
十进制数,赋值给v1,v2;

在打印结果中让v1,v2作为位运算符“~,&,|,^”的参数，运算结果要用dec_to_bstr(){3}函数
转化为十进制;

运算结束后，询问用户是否重新输入,若是从第二行伪代码起重复循环，否则退出;


{1}:输入为二进制字符串,原理为遍历二进制字符,以整数is作为鉴定标记，检查标准为字符中没有0和1以外的数
如果检查成功，is置1，返回检测值is
如果检查失败,is置0
新输入的字符串重新返回检查进行检验，若检查成功is置1，否则置0

(后继：程序根据is作出判断，如果为1，则字符串不变；如果为0，则报错并要求重新输入该字符串
(利用modify()函数修改[4])


在本例中两个函数都得输对才能通过下一个函数

{2}:输入为二进制字符串，循环遍历每一位并将其与2的对应幂相乘并相加，中止条件为
到达字符串的底部'\000

{3}:输入为十进制数n，循环不断将n除2，取n%2赋值给赋值给字符串的对应位
(从size起倒数)，中止条件为n除2等于0,返回结果是二进制字符串bstr

{4}:输入为输错的二进制字符串，用s_gets函数做修改，输入完毕后返回给bcheck函数做检查

伪代码：
获取第一字符串（）已经由s_gets处理）
当第一字符串不是二进制数,报错,重新输入（即再调用s_gets函数输入值）,直至其是为止,
第二类推,两个都得输入正确才能进入下一个步骤

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "s_gets.h"
#include <math.h>
#define SIZE 8

char* bcheck(char* pb);
int bstr_to_dec(char* pb);
char* modify(char* pb);
char* dec_to_bstr(int n,char* bin);
int main()
{
    char bin1[SIZE],bin2[SIZE],bin3[SIZE];
    int v1,v2;
    printf("input bin1 bin2:\n");  
    s_gets(bin1,SIZE);
    s_gets(bin2,SIZE);
    bcheck(bin1);
    bcheck(bin2); 

    v1=bstr_to_dec(bin1);
    v2=bstr_to_dec(bin2);

    printf("Check pass.Your binarynumber is:%s  %s\n",bin1,bin2);
    printf("and decimal number is:%d    %d\n",v1,v2);
    printf("%d & %d = %s",v1,v2,dec_to_bstr(v1&v2,bin3));

}

char* bcheck(char* pb)
{
    char* st=pb;
    int is=1;
    while(*st!='\000')
    {   
        if(*st!='0' && *st!='1')    //检查条件
        {
            is=0;
            modify(pb);
        }
        *st++;
    }      
        
    return pb;
}

int bstr_to_dec(char* pb)
{
   int len=strlen(pb),i=1,dec=0;
   char* st = pb;
    while(*st!='\000')
    {
    dec=dec+((int)*st-48)*pow(2,len-i);
        *st++;
        i++;
    }
    return dec;
}

char* modify(char* pb)
{
    printf("%s is not a binary number,input again:",pb);
    s_gets(pb,SIZE);
    bcheck(pb);
    return pb;
}

char* dec_to_bstr(int n,char* bin)
{
    while(n!=0)
    {   
        bin[SIZE]=(n%2);
        n=n/2;
    }
}






























