/*
Ч��:���г��򣬳���Ҫ���û���������������ַ����������ȡ�ַ����������ɹ���
����ʮ���Ƶ�int������������û��ظ��˹���

���裺
�����ַ������Դ���Ҫ������ַ���
���벢�ó�������ַ���
�����ַ������������麯���������麯��������ڴ��������Ƽ�麯��{1}
ͨ�������Ƽ�麯�����ַ�������ת������{2}��������ʮ���ƽ��

{1}:�����ַ���������ַ�������ʼ������ֵΪbinary=true���ڱ�ʶ�ַ����Ƿ�Ϊ������
�쳣���Ϊ����Ϊ0����1
�����������������쳣�����binary��Ϊfalse��������ֹ����
��������Ϻ����쳣������������ظ�������

{2}:�����ַ���������ַ�������ȡ������������λ����strlen(st)��
�ӵ�һλ��ʼ���϶�Ӧ���ݼ���ʮ���ƣ��㷨Ϊ��
    rel=rel+2^(len-i)*st++

ѭ������
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
        find = strchr(st,'\n'); //����������ַ�����ǰn���ֵķ�Χ���Ƿ��л��з�
        if(find)
            *find = '\0';   //���н�β���Ļ��з������
        else
            while(getchar()!='\n')  //���޽�n������ַ�ȫ������
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
int trans(char* st) //��תʮ
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





































