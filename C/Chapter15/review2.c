/*ʵ��Ч�������г���,����Ҫ�����������ַ���,����󷵻�
�����ַ���������~,&,|,^�������Ķ�����ֵ

α���룺
�����ַ�����bin1,bin2,bin3�洢����������������������v1,v2�洢����ʮ������;

��bin1 bin2����Ҫ����Ķ�������,��������ͨ��bcheck(){1}��������;

����λ������Ĳ�������ʮ����������Ҫbstr_to_dec(){2}���������ַ�ת��Ϊ
ʮ������,��ֵ��v1,v2;

�ڴ�ӡ�������v1,v2��Ϊλ�������~,&,|,^���Ĳ�����������Ҫ��dec_to_bstr(){3}����
ת��Ϊʮ����;

���������ѯ���û��Ƿ���������,���Ǵӵڶ���α�������ظ�ѭ���������˳�;


{1}:����Ϊ�������ַ���,ԭ��Ϊ�����������ַ�,������is��Ϊ������ǣ�����׼Ϊ�ַ���û��0��1�������
������ɹ���is��1�����ؼ��ֵis
������ʧ��,is��0
��������ַ������·��ؼ����м��飬�����ɹ�is��1��������0

(��̣��������is�����жϣ����Ϊ1�����ַ������䣻���Ϊ0���򱨴�Ҫ������������ַ���
(����modify()�����޸�[4])


�ڱ�������������������Բ���ͨ����һ������

{2}:����Ϊ�������ַ�����ѭ������ÿһλ��������2�Ķ�Ӧ����˲���ӣ���ֹ����Ϊ
�����ַ����ĵײ�'\000

{3}:����Ϊʮ������n��ѭ�����Ͻ�n��2��ȡn%2��ֵ����ֵ���ַ����Ķ�Ӧλ
(��size����)����ֹ����Ϊn��2����0,���ؽ���Ƕ������ַ���bstr

{4}:����Ϊ���Ķ������ַ�������s_gets�������޸ģ�������Ϻ󷵻ظ�bcheck���������

α���룺
��ȡ��һ�ַ��������Ѿ���s_gets����
����һ�ַ������Ƕ�������,����,�������루���ٵ���s_gets��������ֵ��,ֱ������Ϊֹ,
�ڶ�����,��������������ȷ���ܽ�����һ������

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
        if(*st!='0' && *st!='1')    //�������
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






























