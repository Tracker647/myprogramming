#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
struct comment      //学生的数据，目前只有评论,可再扩展出学号，用户名，日期等信息
{
    char text[MAX_SIZE];
};
typedef struct LNode        //学生的数据用链表存储
{
    struct comment comment;
    int id;                //节点序号
    struct LNode *prev;
    struct LNode *next;
} LNode;
LNode *head;
LNode *tail;




void InitList(LNode *L)
{
    LNode *p;
    p = L;
    p->prev = NULL;
    p->next = NULL;
    strcpy(p->comment.text, "Head");
}
void InsList_FromHead(LNode *L) //头插法
{
    LNode *head, *newNode;
    head = L;
    int len = 1;
    newNode = (LNode *)malloc(sizeof(LNode));
    if (head->next != NULL)         //多评论情况
    {
        newNode->next = head->next;
        (head->next)->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }
    else                    //只有一个评论情况
    {
        newNode->prev = head;
        head->next = newNode;
        newNode->next = NULL;
    }

    //测量表长以标序
    LNode *p;
    for (p = head->next; p != NULL; p = p->next)
    {
        p->id = len++;
    }
}

int ListLength(LNode head)
{
    LNode *p;
    int len = 0;
    for (p = head.next; p != NULL; p = p->next)
    {
        len++;
    }
    return len;
}
void DelList(int index, LNode *L)
{
    int i = 0;
    LNode *p;
    for (p = L; i < index; i++, p = p->next)    
    {
    }

    if(p->next != NULL)                 //要删除的在链表当中
    {                            
        (p->prev)->next = p->next;
        (p->next)->prev = p->prev;
        free(p);
    }
    else                                //要删除的在链表最前
    {
        free(p);
    }
   
 
}

//菜单，每次功能使用结束后都会调用
int menu()
{
    int choose;
    printf(" ___________________________________\n");
    printf("|        欢迎使用学生留言系统v0.1  |\n");
    printf("|        您要:                     |\n");
    printf("|                1.留言            |\n");
    printf("|                2.查看留言        |\n");
    printf("|                3.删除留言        |\n");
    printf("|                4.修改留言        |\n");
    printf("|                5.退出            |\n");
    printf("|__________________________________|\n");
    printf("请按序号选择功能:\n");
    scanf("%d", &choose);
    return choose;
}

void add(LNode *L)
{
    LNode *p;
    char srcText[MAX_SIZE];
    InsList_FromHead(L);
    p = L->next;
    fflush(stdin);
    printf("请留言:\n");
    scanf("%[^\n]", srcText); //这种写法scanf会一直读取至换行符结束，不会管空格
    strcpy(p->comment.text, srcText);
    printf("你的留言:\n%s\n", p->comment.text);

}
void printOne(LNode *p)
{
    printf("_______________________________\n");
    printf("#%d %s\n",p->id, p->comment.text);
    printf("_______________________________\n");

}
void view(LNode *L)
{
    LNode *p;
    printf("当前所有留言:\n");
    for (p = L->next; p != NULL; p = p->next)
    {
        printOne(p);
    }
}
void del(LNode *L)
{
    int i = 0;
    int len = 1;
    int index;
    char choose;
    LNode *p;

    if(ListLength(*L) == 0)
    {
        printf("当前没有任何可删除的评论!\n");
        return 0;
    }

    view(L);
    printf("输入要删除的评论序号:\n");
    scanf("%d", &index);
    for (p = L; i < index; i++, p = p->next)
    {
    }
    printf("评论内容:\n");
    printOne(p);
    fflush(stdin);  //刷新输入流，避免下一个输入读取上一个输入的换行符
    printf("确定要删除吗? 确定选Y\n");
    scanf("%c",&choose);
    if(toupper(choose)  == 'Y')
    {
        DelList(index,L);
        printf("评论已删除。\n");
    }  

    //删除评论，链表结构改变，要重新标序
    for (p = L->next; p != NULL; p = p->next)
    {
        p->id = len++;
    }
   
}
void modify(LNode *L)
{
    LNode *p;
    int index;
    int i = 0;
    int choose;
    char srcText[MAX_SIZE];
    if(ListLength(*L) == 0)
    {
        printf("当前没有任何可修改的评论!\n");
        return 0;
    }
    view(L);
    printf("输入要修改的评论序号:\n");
    scanf("%d", &index);
    for (p = L; i < index; i++, p = p->next)
    {
    }
    printf("评论内容:\n");
    printOne(p);
    fflush(stdin);  //刷新输入流，避免下一个输入读取上一个输入的换行符

    printf("确定要修改吗? 确定选Y\n");
    scanf("%c",&choose);
    if(toupper(choose)  == 'Y')
    {
        printf("请留言:\n");
        fflush(stdin);
        scanf("%[^\n]", p->comment.text); //这种写法scanf会一直读取至换行符结束，不会管空格
        printf("你的留言:\n%s\n", p->comment.text);
        printf("评论已修改。\n");
    }  
}


int main()
{
    LNode L;
    InitList(&L);
    while (1)
    {
        switch (menu())
        {
            case 1:
                add(&L);
                break;

            case 2:
                view(&L);
                break;

            case 3:
                del(&L);
                break;

            case 4:
                modify(&L);
                break;

            case 5:
                exit(0);

            default:
                fflush(stdin);
                printf("请勿暴力测试!\n");
                break;
        }
    }
}