#include <stdio.h>
int maze[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 4, 4, 4, 0, 4, 0},
    {0, 0, 0, 0, 4, 0, 4, 0},
    {0, 4, 0, 0, 0, 0, 4, 0},
    {0, 4, 0, 4, 4, 0, 4, 0},
    {0, 4, 0, 0, 0, 0, 4, 4},
    {0, 4, 0, 0, 4, 0, 0, 0},
    {0, 4, 4, 4, 4, 4, 4, 0}};

typedef struct
{
    int x;
    int y;
    int pre;
} queue;
queue sq[100];
int qh = 0, qe = 0;

void search();
int check(int i, int j);
void output();
int main()
{
    search();
}
void search()
{
    int i, j, k, moveX = 1, moveY = 1;
    qe++;
    sq[qe].x = 0, sq[qe].y = 0, sq[qe].pre = 0;
    maze[0][0] = -1;
    while (qh != qe)
    {
        qh++;
        // printf("dequeued:(%d,%d) now head:%d rear:%d\n", sq[qh].x, sq[qh].y, qh, qe);
        for (k = 0; k < 2; k++)
        {
            i = sq[qh].x, j = sq[qh].y;
            if (k == 0)
                i = sq[qh].x + moveX;
            else
                j = sq[qh].y + moveY;
            if (check(i, j) == 1)
            {
                qe++;
                sq[qe].x = i;
                sq[qe].y = j;
                sq[qe].pre = qh;
                maze[i][j] = -1;
                // printf("(%d,%d) enqueued now head:%d rear:%d\n", sq[qe].x, sq[qe].y, qh, qe);
                if (sq[qe].x == 7 && sq[qe].y == 7)
                {
                    output();
                    return;
                }
            }
        }
    }
}
int check(int i, int j)
{
    int flag = 1;
    if ((i > 7 || i < 0) || (j > 7 || j < 0))
        flag = 0;
    if (maze[i][j] == -1 || maze[i][j] == 4)
        flag = 0;
    return flag;
}
void output()
{
    queue answer[100];
    int k = 0;
    answer[k].x = sq[qe].x;
    answer[k].y = sq[qe].y;
    k++;
    while (sq[qe].pre != 0)
    {
        qe = sq[qe].pre;
        answer[k].x = sq[qe].x;
        answer[k].y = sq[qe].y;
        k++;
    }
    k--;
    printf("here is the way out:\n");
    while (k >= 0)
    {
        printf("(%d,%d)\n", answer[k].x + 1, answer[k].y + 1);
        k--;
    }
    printf("\n");
}