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
        printf("表已初始化\n");
       
        printf("目前元素:\n");
        ListTraverse(&L);
        printf("\n");

        GetElem(L,5,&e);
        printf("第5个元素的值为：%d\n",e);
        ListDelete(&L,5,&e);
        printf("\n");

        printf("修改后的元素:\n");
        ListTraverse(&L);
        printf("\n");

        ListInsert(&L,4,21);
        printf("修改后的元素:\n");
        ListTraverse(&L);
        ListLength(&L);
        printf("\n");

        printf("待合并的元素LA和LB\n");
        len(&LA);
        ListTraverse(&LA);
        len(&LB);
        ListTraverse(&LB);
        mergelist(&LA,&LB,&LC);
        len(&LC);
        printf("合并后的元素：\n");      
        ListTraverse(&LC);
        printf("\n");
        
        ClearList(&LC);
        printf("求A与B的差集C\n");
        printf("A:\n");
        ListTraverse(&LA);
        printf("B:\n");
        ListTraverse(&LB);
        difference(&LA,&LB,&LC);                                                   
        printf("C:\n");
        ListTraverse(&LC);
}

