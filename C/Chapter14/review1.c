/*效果：输入月份名，打印总天数

伪代码：
声明结构体月（属性为名字，简写，天数，月号）
声明结构体月的12个数组（1-12月）
主函数将月份名传递给输入检查函数{1}，检查函数再传递给输出天数函数{2}

{1}：接收为字符，用strcmp（”m“,months[i]）是否等于0检查输入是否出错
，若出错则打印“Error”并返回-1，若无则传递给输出天数函数，返回值为字符

{2}：接受字符，循环遍历12个数组的name值看是否与字符重合，若重合
则输出天数结果

盲点：对比字符串的函数是什么？
*/

#include<stdio.h>
#include<string.h>
#define size 30
struct month
{
    char name[10];
    char abbrew[4];
    int days;
    int monumb;
};
struct month months[12]=
{
    {"January","jan",31,1},
    {"February","feb",28,2},
    {"March","mar",31,3},
    {"Apri1","apr",30,4},
    {"May","may",31,5},
    {"June","jun",30,6},
    {"July","jul",31,7},
    {"August","aug",31,8},
    {"September","sep",30,9},
    {"October","oct",31,10},
    {"November","nov",30,11},
    {"December","dec",31,12}
};

int days(char*);
char* s_gets(char*st,int n);

int main()
{
    char mon[size];
    int d;
    puts("input month:");
    s_gets(mon,size);
    d=days(mon);
    printf("From first day to this month end %s have %d days.",mon,d);
    return 0;
}
char* s_gets(char*st,int n)
{
    char* ret_val;
    int i=0;
    ret_val = fgets(st,n,stdin);
    if(ret_val)
    {
        while(st[i]!='\n'&&st[i]!='\0')
            i++;
        if(st[i]=='\n')
            st[i]='\0';
        else
            while(getchar()!='\n')
                continue;     
    }
    return ret_val;
}

int days(char* mon)
{
    int index,total;
    for(index=0,total=0;strcmp(mon,months[index-1].name)!=0&&index<=12;
    index++)
    {         
            total += months[index].days;          
    }
    if(index>12||index<1)
    {   printf("No months match!");
            exit(0);
    }
    return(total);      
}