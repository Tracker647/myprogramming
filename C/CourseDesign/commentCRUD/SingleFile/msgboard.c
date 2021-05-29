#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
struct comment //学生的数据，目前只有评论,可再扩展出学号，用户名，日期等信息
{
    char text[MAX_SIZE];
};
typedef struct LNode //学生的数据用链表存储
{
    struct comment comment;
    int id; //节点序号
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
LNode *InsList_FromHead(LNode *L) //头插法
{
    LNode *head, *newNode;
    head = L;
    int len = 0;
    newNode = (LNode *)malloc(sizeof(LNode));
    if (head->next != NULL) //多评论情况
    {
        newNode->next = head->next;
        (head->next)->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }
    else //只有一个评论情况
    {
        newNode->prev = head;
        head->next = newNode;
        newNode->next = NULL;
    }

    //测量表长以标序
    LNode *p;

    for (p = head; p != NULL; p = p->next)
    {
        p->id = len++;
    }

    return head->next;
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

    if (p->next != NULL) //要删除的在链表当中
    {
        (p->prev)->next = p->next;
        (p->next)->prev = p->prev;
        free(p);
    }
    else //要删除的在链表最前
    {
        (p->prev)->next = NULL;
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
char *filePath = "E:\\myprogramming\\C\\Practicing\\commentCRUD\\SingleFile\\datas.txt";
char *lenPath = "E:\\myprogramming\\C\\Practicing\\commentCRUD\\SingleFile\\len.txt";
void loadFromFile(LNode *L)
{
    LNode *p;
    FILE *fp,*num;
    int i, datalen;
    char line[MAX_SIZE];

    if ((fp = fopen(filePath, "r")) == NULL)
    {
        fprintf(stdout, "Can't Open data file,Read failed\n");
        exit(EXIT_FAILURE);
    }
    else if ((num = fopen(lenPath, "r")) == NULL)
    {
        fprintf(stdout, "Can't Open data file,Read failed\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        fprintf(stdout, "数据文件读取成功!\n");
    }

    fscanf(num, "%d", &datalen);
    printf("当前评论数: %d条\n", datalen);

    for (i = 0; i < datalen; i++) //然后回到文件开头,根据数据长度重建链表并赋值
    {
        p = InsList_FromTail(L); //id,前后指针是链表的固有属性，但comment不是，所以需要赋值
        
        fgets(line,MAX_SIZE,fp); 
        strcpy(p->comment.text, line);
    }

    fclose(num);
    fclose(fp);
}

void saveToFile(LNode *L)
{
    FILE *fp = NULL,*num = NULL;
    LNode *p;
    int datalen = 0; //统计数据量
    if ((fp = fopen(filePath, "w+")) == NULL)
    {
        fprintf(stdout, "Can't Open data file,Read failed\n");
        exit(EXIT_FAILURE);
    }
    else if ((num = fopen(lenPath, "w+")) == NULL)
    {
        fprintf(stdout, "Can't Open data file,Read failed\n");
        exit(EXIT_FAILURE);
    }

    for (p = L->next; p != NULL; p = p->next)
    {
        fprintf(fp, "%s", p->comment.text); //将每个节点的所有数据依次写入文件
        datalen++;
    }
  
    fprintf(num, "%d", datalen);  //用另一个文件标记数据的长度

    fclose(num);
    fclose(fp);
}
void s_gets(char *srcText)  //输入的字符串要保留空格和换行符
{
    int i;
    for(i = 0; i < MAX_SIZE;i++){ srcText[i] = NULL; };
    fflush(stdin);
    gets(srcText); 
    for(i = 0; srcText[i]!='\000';i++){}
    srcText[i] = '\n';
 
}
void add(LNode *L)
{
    LNode *p;
    char srcText[MAX_SIZE];
    fflush(stdin);
    printf("请留言:\n");
    s_gets(srcText);

    if(srcText[0] == NULL)
    {
        printf("你未输入任何评论!\n");
        return 0;
    }

   
    InsList_FromHead(L);
    p = L->next;  
    strcpy(p->comment.text, srcText);
    printf("你的留言:\n%s\n", p->comment.text);
   
    //写入文件中
    saveToFile(L);
}
void printOne(LNode *p)
{
    printf("_______________________________\n");
    printf("#%d %s\n", p->id, p->comment.text);
    printf("_______________________________\n");
}
void view(LNode *L)
{

    LNode *p;
    if (L->next == NULL)
    {
        printf("当前没有任何留言!\n");
        return 0;
    }
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

    if (ListLength(*L) == 0)
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
    fflush(stdin); //刷新输入流，避免下一个输入读取上一个输入的换行符
    printf("确定要删除吗? 确定选Y\n");
    scanf("%c", &choose);
    if (toupper(choose) == 'Y')
    {
        DelList(index, L);
        printf("评论已删除。\n");
    }

    //删除评论，链表结构改变，要重新标序
    p = L;
    do
    {
        p = p->next;
        if(p == NULL)
        {
            return 0;
        }
        else{
            p->id = len++;     
        }
                   
    }while(1);

    saveToFile(L);
}
void modify(LNode *L)
{
    LNode *p;
    int index;
    int i = 0;
    int choose;
    char srcText[MAX_SIZE];

    if (ListLength(*L) == 0)
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
    fflush(stdin); //刷新输入流，避免下一个输入读取上一个输入的换行符

    printf("确定要修改吗? 确定选Y\n");
    scanf("%c", &choose);
    if (toupper(choose) == 'Y')
    {
        printf("请留言:\n");
        fflush(stdin);

        s_gets(srcText);
        strcpy(p->comment.text,srcText);

        printf("你的留言:\n%s\n", p->comment.text);
        printf("评论已修改。\n");
    }

    saveToFile(L);
}

int main()
{
    LNode L;
    InitList(&L);
    loadFromFile(&L);
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