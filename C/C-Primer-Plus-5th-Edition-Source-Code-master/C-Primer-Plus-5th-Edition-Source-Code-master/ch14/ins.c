/* book.c -- one-book inventory */
#include <stdio.h>
#define MAXSIZE 20 
typedef int ElemType; /* ElemType类型根据实际情况而定，这里假设为int */
struct seqlist
{
    ElemType data[MAXSIZE]; /* 数组，存储数据元素 */
    int length;             /* 线性表当前长度 */
};                /* end of structure template           */

int main()
{
      struct seqlist L={.data={5,4,3,2,1},.length=5};
      L.length=3;
}