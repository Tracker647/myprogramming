//��ʮ���µ�5С�� ���Żس���



/*
ʵ��Ч�����������,��������ʾ�����е�������ı�ţ�����ʾÿ�γ����Ľ��

[1]��������sample:
����Ϊ�����������鳤�ȣ���ȡ����n
Ҫ�󣺶��ڻ�ȡ�������ܹ����ѡ��n���±겢��ӡ�±�����ֵ
�±겻���ظ���ȡ
�����ظ����ã���Ҫ���ƺ��ӣ�

α���룺
����doubleָ��pick����������������Ϊdouble������i�γ�ȡ
�����random(������е��±꣬�������srand()��rand(),time())


*/
#include <stdio.h>
#include <stdlib.h>
#define SLEN 30 //��������30����
void fillarray(double ar[],int n);  //����������ڵ�����
void showarray(double ar[],int n);  //��ʾ�����ڵ�������
void sample(double ar[],int len,int tick);  //���������������������������������ȡ���������Żأ�
int main()
{
    double myar[SLEN];
    char c='y';
    printf("The balls in the box encoded:\n");
    while(c=='y')
    {   fillarray(myar,SLEN);
        showarray(myar,SLEN);
        sample(myar,SLEN,5);
        printf("The box after picking:\n");
        showarray(myar,SLEN);
        printf("\nWant play again?Press y (other to quit):");
        c=getchar();
        while(getchar()!='\n')
            continue;
    }

}

void fillarray(double ar[],int n)
{
    int index;
    for(index=0;index<n;index++)
    {
        ar[index]=index+1;
    }
}
void showarray(double ar[],int n)
{
    int index;
    for(index=0;index<n;index++)
    {
        if(ar[index]==-1)
        {    
            printf("      picked");
            continue;
        }
        else
        {   
            printf("%10.1lf",ar[index]);
        }
        if(index%6==0)
            printf("\n");
    }
}
void sample(double ar[],int len,int tick)
{
    int random,i,last;  //����鵽�ı�ţ���i�γ�ȡ����һ�γ鵽�ı��ֵ
    printf("\nPicked balls from box:\n");
    for(i=0;i<tick;i++)
    {     
        random = rand()%len;
        printf("ar[%d]=%.1lf\n",random,ar[random]);
        ar[random]=-1;
    }
}