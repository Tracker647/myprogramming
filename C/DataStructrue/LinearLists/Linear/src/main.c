#include <stdio.h>
#include <stdlib.h>
#include "linear_list.h"
#include <string.h>

int main()
{
        ElemType e;
        Status i;
        SeqList L={.data={4,9,15,21,28,30,30,42,51,62}
        },
        LA={.data={4,9,15,21,30,42}},
        LB={.data={3,4,9,15}},
        LC={.data={0}};
        InitList(&L);
        printf("\n");
        printf("���ѳ�ʼ��\n");
       
        printf("ĿǰԪ��:\n");
        ListTraverse(&L);
        printf("\n");

        GetElem(L,5,&e);
        printf("��5��Ԫ�ص�ֵΪ��%d\n",e);
        ListDelete(&L,5,&e);
        printf("\n");

        printf("�޸ĺ��Ԫ��:\n");
        ListTraverse(&L);
        printf("\n");

        ListInsert(&L,4,21);
        printf("�޸ĺ��Ԫ��:\n");
        ListTraverse(&L);
        ListLength(&L);
        printf("\n");

        printf("���ϲ���Ԫ��LA��LB\n");
        len(&LA);
        ListTraverse(&LA);
        len(&LB);
        ListTraverse(&LB);
        mergelist(&LA,&LB,&LC);
        len(&LC);
        printf("�ϲ����Ԫ�أ�\n");      
        ListTraverse(&LC);
        printf("\n");
        
        ClearList(&LC);
        printf("��A��B�ĲC\n");
        printf("A:\n");
        ListTraverse(&LA);
        printf("B:\n");
        ListTraverse(&LB);
        difference(&LA,&LB,&LC);                                                   
        printf("C:\n");
        ListTraverse(&LC);
}

