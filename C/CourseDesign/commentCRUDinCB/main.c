#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
typedef struct comment
{
    char text[MAX_SIZE];
    struct comment *prev;
    struct comment *next;
}nodeList;


//菜单，每次功能使用结束后都会调用
int menu()
{
    int choose;
    printf("___________________________________\n");
    printf("|        欢迎使用学生留言系统v0.1  |\n");
    printf("|        您要:                     |\n");
    printf("|                1.留言            |\n");
    printf("|                2.查看留言        |\n");
    printf("|                3.删除留言        |\n");
    printf("|                4.修改留言        |\n");
    printf("|__________________________________|\n");
    printf("请按序号选择功能:\n");
    scanf("%d",&choose);
    return choose;
}

void add(nodeList* L)
{
    nodeList *p;
    nodeList *newcomment = (nodeList*)malloc(sizeof(nodeList));
    printf("请输入评论:");
    scanf("%s",newcomment->text);
    for(p = L;p!=NULL;p=p->next)
    {

    }
    printf("%s\n",p->text);
    p->next = newcomment;
    printf("新评论: %s\n",newcomment->text);

}
void view(nodeList* L)
{

}
void del(nodeList* L)
{

}
void modify(nodeList* L)
{

}

void Initlist(nodeList* L)
{

    L->prev = NULL;
    L->next = NULL;
    strcpy(L->text, "head");
}
int main()
{
    nodeList L;
    Initlist(&L);
    switch(menu())
    {
        case 1:add(&L);break;

        case 2:view(&L);break;

        case 3:del(&L);break;

        case 4:modify(&L);break;

        case 5:exit(0);
    }



}



