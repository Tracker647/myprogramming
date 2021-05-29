#include <stdio.h>
#include "queue.h"
int main()
{
	queue bfs;
	int i;
	initQueue(&bfs);
	for (i = 0; i < 9; i++)
		enQueue(&bfs, i);
	printf("data in bfs queue:\n");
	for (i = 0; i < 9; i++)
	{
		printf("%d ", bfs.data[i]);
	}
	printf("\n");
	int e;
	int rubbish[9] = {0};
	for (i = 0; i < 8; i++)
	{
		deQueue(&bfs, &e);
		rubbish[i] = e;
	}
	printf("data in bfs queue:\n");
	for (i = bfs.front; i < bfs.rear; i++)
	{
		printf("%d ", bfs.data[i]);
	}
	printf("\n");
	printf("dequeued data in rubbish array:\n");
	for (i = 0; i < bfs.front; i++)
	{
		printf("%d ", rubbish[i]);
	}
	printf("\n");

	return 0;
}