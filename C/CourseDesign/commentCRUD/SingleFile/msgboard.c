#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
struct comment //ѧ�������ݣ�Ŀǰֻ������,������չ��ѧ�ţ��û��������ڵ���Ϣ
{
    char text[MAX_SIZE];
};
typedef struct LNode //ѧ��������������洢
{
    struct comment comment;
    int id; //�ڵ����
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
LNode *InsList_FromHead(LNode *L) //ͷ�巨
{
    LNode *head, *newNode;
    head = L;
    int len = 0;
    newNode = (LNode *)malloc(sizeof(LNode));
    if (head->next != NULL) //���������
    {
        newNode->next = head->next;
        (head->next)->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }
    else //ֻ��һ���������
    {
        newNode->prev = head;
        head->next = newNode;
        newNode->next = NULL;
    }

    //�������Ա���
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

    if (p->next != NULL) //Ҫɾ������������
    {
        (p->prev)->next = p->next;
        (p->next)->prev = p->prev;
        free(p);
    }
    else //Ҫɾ������������ǰ
    {
        (p->prev)->next = NULL;
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
        fprintf(stdout, "�����ļ���ȡ�ɹ�!\n");
    }

    fscanf(num, "%d", &datalen);
    printf("��ǰ������: %d��\n", datalen);

    for (i = 0; i < datalen; i++) //Ȼ��ص��ļ���ͷ,�������ݳ����ؽ�������ֵ
    {
        p = InsList_FromTail(L); //id,ǰ��ָ��������Ĺ������ԣ���comment���ǣ�������Ҫ��ֵ
        
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
    int datalen = 0; //ͳ��������
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
        fprintf(fp, "%s", p->comment.text); //��ÿ���ڵ��������������д���ļ�
        datalen++;
    }
  
    fprintf(num, "%d", datalen);  //����һ���ļ�������ݵĳ���

    fclose(num);
    fclose(fp);
}
void s_gets(char *srcText)  //������ַ���Ҫ�����ո�ͻ��з�
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
    printf("������:\n");
    s_gets(srcText);

    if(srcText[0] == NULL)
    {
        printf("��δ�����κ�����!\n");
        return 0;
    }

   
    InsList_FromHead(L);
    p = L->next;  
    strcpy(p->comment.text, srcText);
    printf("�������:\n%s\n", p->comment.text);
   
    //д���ļ���
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
        printf("��ǰû���κ�����!\n");
        return 0;
    }
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

    if (ListLength(*L) == 0)
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
    fflush(stdin); //ˢ����������������һ�������ȡ��һ������Ļ��з�
    printf("ȷ��Ҫɾ����? ȷ��ѡY\n");
    scanf("%c", &choose);
    if (toupper(choose) == 'Y')
    {
        DelList(index, L);
        printf("������ɾ����\n");
    }

    //ɾ�����ۣ�����ṹ�ı䣬Ҫ���±���
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
    fflush(stdin); //ˢ����������������һ�������ȡ��һ������Ļ��з�

    printf("ȷ��Ҫ�޸���? ȷ��ѡY\n");
    scanf("%c", &choose);
    if (toupper(choose) == 'Y')
    {
        printf("������:\n");
        fflush(stdin);

        s_gets(srcText);
        strcpy(p->comment.text,srcText);

        printf("�������:\n%s\n", p->comment.text);
        printf("�������޸ġ�\n");
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
            printf("����������!\n");
            break;
        }
    }
}