/*Ч���������·�������ӡ������

α���룺
�����ṹ���£�����Ϊ���֣���д���������ºţ�
�����ṹ���µ�12�����飨1-12�£�
���������·������ݸ������麯��{1}����麯���ٴ��ݸ������������{2}

{1}������Ϊ�ַ�����strcmp����m��,months[i]���Ƿ����0��������Ƿ����
�����������ӡ��Error��������-1�������򴫵ݸ������������������ֵΪ�ַ�

{2}�������ַ���ѭ������12�������nameֵ���Ƿ����ַ��غϣ����غ�
������������

ä�㣺�Ա��ַ����ĺ�����ʲô��
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