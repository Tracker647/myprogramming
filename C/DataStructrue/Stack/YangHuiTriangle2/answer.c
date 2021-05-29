#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000 //队列的最大长度
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];//队列的存储空间
    int front,rear;//队列的队头指针和队尾指针
}CyQueue;
//初始化队列
void Init_CyQueue(CyQueue *Q){
    Q->front = Q->rear =0;
}
//判断队列是否为空
int Empty_CyQueue(CyQueue *Q){
    return Q->rear == Q->front;//为真，返回1 则表示队列为空
}
//数据 e 进队列
void In_CyQueue(CyQueue *Q, int e){
    if(Q->rear == MAXSIZE){
        return;
    }
    Q->data[Q->rear] = e;
    Q->rear+=1;
}
//数据出队列，通过将出队列数据赋值给 e
void Out_CyQueue(CyQueue *Q,int *e){
    //出队之前，先判断队列是否为空
    if(Q->rear == Q->front){
        return;
    }
    *e = Q->data[Q->front];
    Q->front+=1;
}
//获取队头元素的值
void Front_CyQueue(CyQueue * Q,ElemType *x){
    if(Empty_CyQueue(Q)){
        return;
    }else{
        *x=Q->data[Q->front];
    }
}
//杨辉三角实现函数
void yanghui(int n){
    CyQueue Q;
    int i,s,e,k;
    //由于杨辉三角越往下，值的位数越多，为了保持输出数据的形状，杨辉三角第一行中的1需要空多个格
    for(i=1;i<=n;i++){
        printf("   ");
    }
    //输出 1，需要控制其所占位数
    printf("%-5d\n",1);
    //初始化队列，同时将三角的第二行作为起始行，向下推导
    Init_CyQueue(&Q);
    In_CyQueue(&Q,0);
    In_CyQueue(&Q,1);
    In_CyQueue(&Q,1);
    k=1;
    while(k<n){
        //每往下一行，其第一个数字都需往左移动 1 个占位
        for(i=1;i<=n-k;i++){
            printf("   ");
        }
        // 0 作为转行符，入队列
        In_CyQueue(&Q,0);
        do{
            //队头元素出队列
            Out_CyQueue(&Q,&s);
            //取新的队头元素
            Front_CyQueue(&Q,&e);
            //如果所取元素非 0，则输出，否则做转行操作
            if(e){
                printf("%-5d",e);
            }
            else{
                printf(" \n");
            }
            
            In_CyQueue(&Q,s+e);
        }while(e!=0);//一旦 e 值为 0，即做转行操作，退出循环，开始新一行的排列
        k++;
    }
    //出循环后，队列中还存有下一行的数据
    Out_CyQueue(&Q,&e);
    while(!Empty_CyQueue(&Q)){
        Out_CyQueue(&Q,&e);
        printf("%-5d",e);
    }
}
int main(){
    yanghui(10);
    return 0;
}