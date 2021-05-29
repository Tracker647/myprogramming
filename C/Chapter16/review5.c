//第十六章第5小题 不放回抽样



/*
实现效果：输入程序,程序能显示盒子中的所有球的编号，并显示每次抽样的结果

[1]抽样函数sample:
输入为数组名，数组长度，抽取次数n
要求：对于获取的数组能够随机选择n个下标并打印下标代表的值
下标不能重复抽取
可以重复调用（需要重制盒子）

伪代码：
定义double指针pick（因数组数据类型为double），第i次抽取
随机数random(代表抽中的下标，数需调用srand()和rand(),time())


*/
#include <stdio.h>
#include <stdlib.h>
#define SLEN 30 //盒子里有30个球
void fillarray(double ar[],int n);  //随机给盒子内的球编号
void showarray(double ar[],int n);  //显示盒子内的所有球
void sample(double ar[],int len,int tick);  //数组名（盒子名），盒子里的球数，摸取次数（不放回）
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
    int random,i,last;  //随机抽到的编号，第i次抽取，上一次抽到的编号值
    printf("\nPicked balls from box:\n");
    for(i=0;i<tick;i++)
    {     
        random = rand()%len;
        printf("ar[%d]=%.1lf\n",random,ar[random]);
        ar[random]=-1;
    }
}