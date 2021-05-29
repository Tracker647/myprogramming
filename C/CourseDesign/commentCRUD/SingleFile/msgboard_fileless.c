#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
struct comment      //ѧ�������ݣ�Ŀǰֻ������,������չ��ѧ�ţ��û��������ڵ���Ϣ
{
    char text[MAX_SIZE];
};
typedef struct LNode        //ѧ��������������洢
{
    struct comment comment;
    int id;                //�ڵ����
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
void InsList_FromHead(LNode *L) //ͷ�巨
{
    LNode *head, *newNode;
    head = L;
    int len = 1;
    newNode = (LNode *)malloc(sizeof(LNode));
    if (head->next != NULL)         //���������
    {
        newNode->next = head->next;
        (head->next)->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }
    else                    //ֻ��һ���������
    {
        newNode->prev = head;
        head->next = newNode;
        newNode->next = NULL;
    }

    //�������Ա���
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

    if(p->next != NULL)                 //Ҫɾ������������
    {                            
        (p->prev)->next = p->next;
        (p->next)->prev = p->prev;
        free(p);
    }
    else                                //Ҫɾ������������ǰ
    {
        free(p);
    }
   
 
}

//�˵���ÿ�ι���ʹ�ý����󶼻����
int menu()
{
    int choose;
    printf(" ___________________________________\n");
    printf("|        ��ӭʹ��ѧ������ϵͳv0.1  |\n");
    printf("|        ��Ҫ:                     |\n");
    printf("|                1.����            |\n");
    printf("|                2.�鿴����        |\n");
    printf("|                3.ɾ������        |\n");
    printf("|                4.�޸�����        |\n");
    printf("|                5.�˳�            |\n");
    printf("|__________________________________|\n");
    printf("�밴���ѡ����:\n");
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
    printf("������:\n");
    scanf("%[^\n]", srcText); //����д��scanf��һֱ��ȡ�����з�����������ܿո�
    strcpy(p->comment.text, srcText);
    printf("�������:\n%s\n", p->comment.text);

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
    printf("��ǰ��������:\n");
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
        printf("��ǰû���κο�ɾ��������!\n");
        return 0;
    }

    view(L);
    printf("����Ҫɾ�����������:\n");
    scanf("%d", &index);
    for (p = L; i < index; i++, p = p->next)
    {
    }
    printf("��������:\n");
    printOne(p);
    fflush(stdin);  //ˢ����������������һ�������ȡ��һ������Ļ��з�
    printf("ȷ��Ҫɾ����? ȷ��ѡY\n");
    scanf("%c",&choose);
    if(toupper(choose)  == 'Y')
    {
        DelList(index,L);
        printf("������ɾ����\n");
    }  

    //ɾ�����ۣ�����ṹ�ı䣬Ҫ���±���
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
        printf("��ǰû���κο��޸ĵ�����!\n");
        return 0;
    }
    view(L);
    printf("����Ҫ�޸ĵ��������:\n");
    scanf("%d", &index);
    for (p = L; i < index; i++, p = p->next)
    {
    }
    printf("��������:\n");
    printOne(p);
    fflush(stdin);  //ˢ����������������һ�������ȡ��һ������Ļ��з�

    printf("ȷ��Ҫ�޸���? ȷ��ѡY\n");
    scanf("%c",&choose);
    if(toupper(choose)  == 'Y')
    {
        printf("������:\n");
        fflush(stdin);
        scanf("%[^\n]", p->comment.text); //����д��scanf��һֱ��ȡ�����з�����������ܿո�
        printf("�������:\n%s\n", p->comment.text);
        printf("�������޸ġ�\n");
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
                printf("����������!\n");
                break;
        }
    }
}