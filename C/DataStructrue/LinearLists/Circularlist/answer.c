#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Student)
#define N 7
struct Student                  //��������ѧ����������
{
    int number;
    int password;
    struct Student *next;
};


struct Student *creat(void)         //�������ѧ����Ϣ��Լ��0,0����
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

void Joseph(struct Student *head,int count)  //��Ϸ���ڣ�����Լɪ�򻷹������У���������
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

void main()                //������������ѧ����Ϣ������ֵ
{
    struct Student *Head;
    int num;
    printf("��������˵���ź����룺\n");
    Head=creat();
    printf("��ָ����ʼ��������ֵ��\n");
    scanf("%d",&num);
    Joseph(Head,num);
}