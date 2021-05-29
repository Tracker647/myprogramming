#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "queue.h"
#define N 8 //城市数
int charConvertIndex(char c);
void shortestPath(int start);
int graph[N][N] = {
	{0, 1, 1, 1, 0, 1, 0, 0},
	{1, 0, 0, 0, 0, 1, 0, 0},
	{1, 0, 0, 1, 1, 0, 0, 0},
	{1, 0, 1, 0, 0, 0, 1, 0},
	{0, 0, 1, 0, 0, 0, 1, 1},
	{1, 1, 0, 0, 0, 0, 0, 1},
	{0, 0, 0, 1, 1, 0, 0, 1},
	{0, 0, 0, 0, 1, 1, 1, 0}};
int main()
{
	int start_index;
	char start;
	printf("input start city:\n");
	scanf("%c", &start);
	start_index = charConvertIndex(start);
	// printf("you start city index: %d\n", start_index);
	shortestPath(start_index);

	return 0;
}
int charConvertIndex(char c)
{
	return toupper(c) - 65;
}
void shortestPath(int start)
{
	int i, step, path[N] = {-1}, visit[N] = {0};
	queue bfs;
	if (start > N - 1 || start < 0)
	{
		printf("invaild start!");
		return 0;
	}
	visit[start] = 1;
	initQueue(&bfs);
	enQueue(&bfs, start);
	do
	{
		deQueue(&bfs, &step);
		for (i = 0; i < N; i++)
		{
			if (i == start)
				continue;
			if (graph[step][i] == 1 && visit[i] == 0)
			{
				enQueue(&bfs, i);
				visit[i] = 1;
				path[i] = step;
			}
		}
	} while (bfs.front != bfs.rear);

	char end, answer[N];
	int end_index, k = 0;
	printf("input end:\n");
	fflush(stdin);
	scanf("%c", &end);
	end_index = charConvertIndex(end);
	// printf("you start city index: %d\n", end_index);
	int pre = end_index;
	answer[k++] = pre + 65;
	while (pre != start)
	{
		pre = path[pre];
		answer[k++] = pre + 65;
	}
	printf("The optinum route:\n");
	for (i = strlen(answer); i >= 0; i--)
			printf("%c ",answer[i]);
}