#include <stdio.h>
#include <stdlib.h>
#include "linear_list.h"


Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

/* ��ʼ��˳�����Ա� */
Status InitList(SeqList *L) 
{ 
    L->length=0;
    return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
Status ListEmpty(SeqList L)
{ 
	if(L.length==0)
		return TRUE;
	else
		return FALSE;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
Status ClearList(SeqList *L)
{ 
    int i;
    ListLength(L);
    for(i=0;i<L->length+1;i++)
        L->data[i]=NULL;
    L->length=0;
    return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int ListLength(SeqList *L)
{
    int i;
    for(i=0;L->data[i]!=NULL;i++)
    L->length=i;
    // printf("Ŀǰ����:%d\n",L->length+1);
    return L->length;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int len(SeqList *L)
{
    int i;
    for(i=0;L->data[i]!=NULL;i++)
    L->length=i;
    printf("Ŀǰ����:%d\n",L->length+1);
    return L->length;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ,ע��i��ָλ�ã���1��λ�õ������Ǵ�0��ʼ */
Status GetElem(SeqList L,int i,ElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)
            return ERROR;
    *e=L.data[i-1];

    return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
/* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
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


/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status ListInsert(SeqList *L,int i,ElemType e)
{ 
	printf("��ʼ��Ӳ��������%d�ڱ��ڵ�%dλ\n",e,i);
    int k;
	if (L->length==MAXSIZE)  /* ˳�����Ա��Ѿ��� */
		return ERROR;
	if (i<1 || i>L->length+1)/* ��i�ȵ�һλ��С���߱����һλ�ú�һλ�û�Ҫ��ʱ */
		return ERROR;

	if (i<=L->length)        /* ����������λ�ò��ڱ�β */
	{
		for(k=L->length-1;k>=i-1;k--)  /* ��Ҫ����λ��֮�������Ԫ������ƶ�һλ */
			L->data[k+1]=L->data[k];
	}
	L->data[i-1]=e;          /* ����Ԫ�ز��� */
	L->length++;

	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status ListDelete(SeqList *L,int i,ElemType *e) 
{ 
    printf("��ʼɾ��������ɾ�����ڵĵ�%d��Ԫ��%d\n",i,*e);
    int k;
    if (L->length==0)               /* ���Ա�Ϊ�� */
		return ERROR;
    if (i<1 || i>L->length)         /* ɾ��λ�ò���ȷ */
        return ERROR;
    *e=L->data[i-1];
    if (i<L->length)                /* ���ɾ���������λ�� */
    {
        for(k=i;k<L->length+1;k++)/* ��ɾ��λ�ú��Ԫ��ǰ�� */
			L->data[k-1]=L->data[k];
    }
    L->data[L->length]='\000';
    L->length--;
    return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
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
                if(LC->data[l]==LA->data[i]) //����C���б�Աȣ������ظ�Ԫ��¼��C
                {i++;}
            }
            if(i<=LA->length) //��ֹ����Խ��Ѻ���Ŀ�ֵ����C
            {
                LC->data[k]=LA->data[i];
                i++;k++;
            }
        }
        else
        {
            for(l=0;LC->data[l]!='\000';l++)
            {
                if(LC->data[l]==LB->data[j]) //����C���б�Աȣ������ظ�Ԫ��¼��C
                {j++;}
            }
            if(j<LB->length)    //��ֹ����Խ��Ѻ���Ŀ�ֵ����C
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
            if(LC->data[l]==LA->data[i]) //����C���б�Աȣ������ظ�Ԫ��¼��C
            {i++;}
        }
        LC->data[k]=LA->data[i];
        i++;k++;
    }

    while(j<=LB->length)
    {
        for(l=0;LC->data[l]!='\000';l++)
            {
                if(LC->data[l]==LB->data[j]) //����C���б�Աȣ������ظ�Ԫ��¼��C
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
























