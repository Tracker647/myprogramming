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


//�˵���ÿ�ι���ʹ�ý����󶼻����
int menu()
{
    int choose;
    printf("___________________________________\n");
    printf("|        ��ӭʹ��ѧ������ϵͳv0.1  |\n");
    printf("|        ��Ҫ:                     |\n");
    printf("|                1.����            |\n");
    printf("|                2.�鿴����        |\n");
    printf("|                3.ɾ������        |\n");
    printf("|                4.�޸�����        |\n");
    printf("|__________________________________|\n");
    printf("�밴���ѡ����:\n");
    scanf("%d",&choose);
    return choose;
}

void add(nodeList* L)
{
    nodeList *p;
    nodeList *newcomment = (nodeList*)malloc(sizeof(nodeList));
    printf("����������:");
    scanf("%s",newcomment->text);
    for(p = L;p!=NULL;p=p->next)
    {

    }
    printf("%s\n",p->text);
    p->next = newcomment;
    printf("������: %s\n",newcomment->text);

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



