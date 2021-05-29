#include <stdio.h>
#include "queue.h"
status initQueue(queue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    printf("successful initialize queue\n");
    return OK;
}

status isQueueEmpty(queue Q)
{
    if (Q.front == Q.rear)
        return TRUE;
    else
    {
        return FALSE;
    }
}

status enQueue(queue *Q, elemtype e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
    {
        printf("the queue is full!");
        return ERROR;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    printf("successfully enqueue %d.now queue head in %d,tail in %d\n", e, Q->front, Q->rear);
    return OK;
}

status deQueue(queue *Q, int *e)
{
    if (Q->front == Q->rear)
    {
        printf("the queue is empty!");
        return ERROR;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    printf("successfully dequeue %d.now queue head in %d,tail in %d\n", *e, Q->front, Q->rear);
    return OK;
}