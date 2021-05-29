#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

#define TSIZE 5//�洢��Ӱ���������С
struct film
{
    char title[TSIZE];
    int rating;
};

/* һ�����Ͷ��� */
typedef struct film Item;

typedef struct node
{
    Item item;
    struct node *next;
} Node;

typedef Node *List;

/* ����ԭ�� */

/* /* ��������ʼ��һ������
/* ǰ������: plistָ��һ������
/*���������� �����ʼ��Ϊ�� */
void InitializeList (List * plist);

/* /*������
ǰ������: ȷ�������Ƿ�Ϊ�ն���, plistָ��һ���ѳ�ʼ��������
/*���������� �������Ϊ��,�ú�������true;���򷵻�false */
bool ListIsEmpty(const List *plist);

/* /*����:
ǰ������: ȷ�������Ƿ�����, plistָ��һ���ѳ�ʼ��������
/*��������: �����������,�ú���������;���򷵻ؼ� */
bool ListIsFull (const List *plist);

/* /* ����:
ǰ������: ȷ�������е�����, plistָ��һ���ѳ�ʼ��������
/*���������� �ú������������е����� */
unsigned int ListItemCount (const List *plist);


/* /*�������������ĩβ�����
/*ǰ������: item��һ����������������, plistָ��һ���ѳ�ʼ��������
/*�����������������,�ú���������ĩβ���һ����,�ҷ���true;���򷵻�false */
bool AddItem (Item item, List*plist);

/* /*�������Ѻ��������������е�ÿһ��
/*plistָ��һ���ѳ�ʼ��������
/*pfunָ��һ������,�ú�������һ��Item���͵Ĳ���,���޷���ֵ
/*��������: pfunָ��ĺ��������������е�ÿһ��һ�� */
void Traverse (const List *plist, void (*pfun) (Item item));

/* /*����:�ͷ��ѷ�����ڴ�(����еĻ�)
        plistָ��һ���ѳ�ʼ��������
/*��������: �ͷ���Ϊ�������������ڴ�,��������Ϊ�� */
void EmptyTheList (List *plist);

#endif