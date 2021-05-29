#ifndef _QUEEN_H_
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
typedef int status;
typedef int elemtype;
typedef struct
{
    elemtype data[MAXSIZE];
    int front;
    int rear;
} queue;

status initQueue(queue *Q);
status isQueueEmpty(queue Q);
status enQueue(queue *Q, elemtype e);
status deQueue(queue *Q,int *e);

#endif