#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Student)
#define N 7
struct Student                  //用链表建立学生数据类型
{
    int number;
    int password;
    struct Student *next;
};


struct Student *creat(void)         //输入具体学生信息，约定0,0结束
{
    struct Student *head;
    struct Student *p1,*p2;
    int n=0;
    p1=p2=(struct Student *)malloc(LEN);
    scanf("%d,%d",&p1->number,&p1->password);
    head=NULL;
    while(p1->number!=0)
    {
        n=n+1;
        if(n==1)head=p1;
        else p2->next=p1;
        p2=p1;
        p1=(struct Student *)malloc(LEN);
        scanf("%d,%d",&p1->number,&p1->password);
    }
    p2->next=head;
    return(head);
}

void Joseph(struct Student *head,int count)  //游戏环节，按照约瑟夫环规则运行，并输出结果
{
    int m;
    struct Student *p;
    p=head;
    
        for(m=1;m<count-1;m++)
            p=p->next;
        printf("%d,%d\n",(p->next)->number,(p->next)->password);
        count=p->next->password;
        p->next=p->next->next;
    do{
        for(m=1;m<count;m++)
            p=p->next;
        printf("%d,%d\n",(p->next)->number,(p->next)->password);
        count=p->next->password;
        p->next=p->next->next;
    
    }while(p!=p->next);

    printf("%d,%d\n",p->number,p->password);
}

void main()                //主函数，输入学生信息和上限值
{
    struct Student *Head;
    int num;
    printf("请输入个人的序号和密码：\n");
    Head=creat();
    printf("请指定初始报数上限值：\n");
    scanf("%d",&num);
    Joseph(Head,num);
}