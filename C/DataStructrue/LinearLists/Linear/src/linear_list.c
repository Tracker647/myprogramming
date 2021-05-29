#include <stdio.h>
#include <stdlib.h>
#include "linear_list.h"


Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

/* 初始化顺序线性表 */
Status InitList(SeqList *L) 
{ 
    L->length=0;
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(SeqList L)
{ 
	if(L.length==0)
		return TRUE;
	else
		return FALSE;
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(SeqList *L)
{ 
    int i;
    ListLength(L);
    for(i=0;i<L->length+1;i++)
        L->data[i]=NULL;
    L->length=0;
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(SeqList *L)
{
    int i;
    for(i=0;L->data[i]!=NULL;i++)
    L->length=i;
    // printf("目前长度:%d\n",L->length+1);
    return L->length;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int len(SeqList *L)
{
    int i;
    for(i=0;L->data[i]!=NULL;i++)
    L->length=i;
    printf("目前长度:%d\n",L->length+1);
    return L->length;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
Status GetElem(SeqList L,int i,ElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)
            return ERROR;
    *e=L.data[i-1];

    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem(SeqList L,ElemType e)
{
    int i;
    if (L.length==0)
            return 0;
    for(i=0;i<L.length;i++)
    {
            if (L.data[i]==e)
                    break;
    }
    if(i>=L.length)
            return 0;

    return i+1;
}


/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(SeqList *L,int i,ElemType e)
{ 
	printf("开始添加操作，添加%d于表内第%d位\n",e,i);
    int k;
	if (L->length==MAXSIZE)  /* 顺序线性表已经满 */
		return ERROR;
	if (i<1 || i>L->length+1)/* 当i比第一位置小或者比最后一位置后一位置还要大时 */
		return ERROR;

	if (i<=L->length)        /* 若插入数据位置不在表尾 */
	{
		for(k=L->length-1;k>=i-1;k--)  /* 将要插入位置之后的数据元素向后移动一位 */
			L->data[k+1]=L->data[k];
	}
	L->data[i-1]=e;          /* 将新元素插入 */
	L->length++;

	return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(SeqList *L,int i,ElemType *e) 
{ 
    printf("开始删除操作：删除表内的第%d个元素%d\n",i,*e);
    int k;
    if (L->length==0)               /* 线性表为空 */
		return ERROR;
    if (i<1 || i>L->length)         /* 删除位置不正确 */
        return ERROR;
    *e=L->data[i-1];
    if (i<L->length)                /* 如果删除不是最后位置 */
    {
        for(k=i;k<L->length+1;k++)/* 将删除位置后继元素前移 */
			L->data[k-1]=L->data[k];
    }
    L->data[L->length]='\000';
    L->length--;
    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(SeqList *L)
{
	int i;
    ListLength(L);
    for(i=0;i<L->length+1;i++)
            visit(L->data[i]);
    printf("\n");
    return OK;
}

void mergelist(SeqList *LA, SeqList *LB, SeqList* LC)
{
    int i,j,k,l;
    i=0;j=0;k=0;

    while(i<=LA->length && j<=LB->length)
    {
        if(LA->data[i]<=LB->data[j])
        {
            for(l=0;LC->data[l]!='\000';l++)
            {
                if(LC->data[l]==LA->data[i]) //遍历C与列表对比，避免重复元素录入C
                {i++;}
            }
            if(i<=LA->length) //防止表先越界把后面的空值赋给C
            {
                LC->data[k]=LA->data[i];
                i++;k++;
            }
        }
        else
        {
            for(l=0;LC->data[l]!='\000';l++)
            {
                if(LC->data[l]==LB->data[j]) //遍历C与列表对比，避免重复元素录入C
                {j++;}
            }
            if(j<LB->length)    //防止表先越界把后面的空值赋给C
            {
                LC->data[k]=LB->data[j];
                j++;k++;
            }
               
        }
        
    }
    while(i<=LA->length)
    {
        
        for(l=0;LC->data[l]!='\000';l++)
        {
            if(LC->data[l]==LA->data[i]) //遍历C与列表对比，避免重复元素录入C
            {i++;}
        }
        LC->data[k]=LA->data[i];
        i++;k++;
    }

    while(j<=LB->length)
    {
        for(l=0;LC->data[l]!='\000';l++)
            {
                if(LC->data[l]==LB->data[j]) //遍历C与列表对比，避免重复元素录入C
                {j++;}
            }
        LC->data[k]=LB->data[j];
        j++;k++;
    }
    LC->length=(LA->length)+(LB->length);
   
}


void difference(SeqList *LA, SeqList *LB, SeqList* LC)
{
    int i,j,k=0,flag;
    for(i=0;i<=LA->length+1;i++)
    {
        flag=1;
        for(j=0;j<=LB->length+1;j++)
        {
            if(LB->data[j]==LA->data[i])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            LC->data[k]=LA->data[i];
            k++;
        }
    }
        
}
























