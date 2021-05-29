#include <stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define SIZE 30
struct  Students
{
    int order;
    char name[5];
    int score;

};

typedef struct Students Stu;

int ordercmp(const void *a,const void *b)
{
    Stu *c = (Stu*)a;
    Stu *d = (Stu*)b;
    return c->order > d->order ? 1 : -1;
      
}

int scorecmp(const void *a,const void *b)
{
    Stu *c = (Stu*)a;
    Stu *d = (Stu*)b;

    if(c->score!=d->score)
    {
        return c->score > d->score ? 1 : -1;
    } 
    else  
    {
        return c->order > d->order ? 1 : -1;
    }  
        
      
}

void Initlize(Stu* p)   //初始化结构体数据
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        (p + i)->order = '\000';
        (p + i)->score = '\000';
    }
}

int StructLen(Stu* p)
{
    int len;
    for (len = 0; (p->order)>0 ; len++, p++)
    {

    }
    return len;
}
int main()
{
    Stu student[SIZE];
    Initlize(student);  //初始化结构体数组的值

    Stu *p;
    int i=0,len,n;
    printf("输入学生数n:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("输入第%d个学生的学号,姓名,分数:\n",i+1);
        scanf("%d",&student[i].order);
        scanf("%s",student[i].name);
        scanf("%d",&student[i].score);

        printf("\n");
    }

    // student[0].order = 403; //  初始化
    // student[0].name = "zdz";
    // student[0].score = 62;

    // student[1].order = 402; 
    // student[1].name = "zdl";
    // student[1].score = 79;

    // student[2].order = 407; 
    // student[2].name = "zxl";
    // student[2].score = 79;

    // student[3].order = 401; 
    // student[3].name = "hwq";
    // student[3].score = 79;

    // student[4].order = 400; 
    // student[4].name = "zdx";
    // student[4].score = 83;

    // student[5].order = 408; 
    // student[5].name = "zdx";
    // student[5].score = 83;

    // student[6].order = 404; 
    // student[6].name = "zdx";
    // student[6].score = 83;

    len = StructLen(student);

    printf("初始记录:\n");
    for(p=student;p->score!='\000';p++)
    {
        printf("学号:%d\n姓名:%s\n分数:%d\n\n",p->order,p->name,p->score);
    }

    printf("按学号排序(输入 0):\n");

    qsort(student,len,sizeof(student[0]),ordercmp);
    for(p=student;p->score!='\000';p++)
    {
        printf("学号:%d\n姓名:%s\n分数:%d\n\n\n",p->order,p->name,p->score);
    }
    printf("\n");

    printf("再按分数排序(输入 1):\n");

    qsort(student,len,sizeof(student[0]),scorecmp);
    for(p=student;p->score!='\000';p++)
    {
        printf("学号:%d\n姓名:%s\n分数:%d\n\n",p->order,p->name,p->score);
    }

    printf("\n");
    return 0;
}