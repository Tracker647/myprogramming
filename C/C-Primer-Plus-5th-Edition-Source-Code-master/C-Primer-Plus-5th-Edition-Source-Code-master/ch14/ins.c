/* book.c -- one-book inventory */
#include <stdio.h>
#define MAXSIZE 20 
typedef int ElemType; /* ElemType���͸���ʵ������������������Ϊint */
struct seqlist
{
    ElemType data[MAXSIZE]; /* ���飬�洢����Ԫ�� */
    int length;             /* ���Ա�ǰ���� */
};                /* end of structure template           */

int main()
{
      struct seqlist L={.data={5,4,3,2,1},.length=5};
      L.length=3;
}