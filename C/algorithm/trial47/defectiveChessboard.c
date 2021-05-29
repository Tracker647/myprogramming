#include <stdio.h>
int amount = 1, Board[100][100] = {0};
void cover(int tc, int tr, int dc, int dr, int size);
void outPutBoard(int size);
int main()
{
    int size = 1, x, y, i, j, k;
    printf("input the size of chessboard:\n");
    scanf("%d", &k);
    for (i = 1; i <= k; i++)
        size = size * 2;
    printf("input the coordinate defective pane:\n");
    scanf("%d %d", &x, &y);
    cover(0, 0, x, y, size);
    printf("\n");
    outPutBoard(size);
}
void cover(int tc, int tr, int dc, int dr, int size)
{
    int s, t;
    if (size < 2)
        return;
    t = amount++; //所用三格板当前序号
    s = size / 2; //子问题棋盘大小

    if (dc < tc + s && dr < tr + s) //残缺方格位于左上棋盘
    {

        Board[tc + s - 1][tr + s] = t; //覆盖1号三格板
        Board[tc + s][tr + s - 1] = t;
        Board[tc + s][tr + s] = t;
        cover(tc, tr, dc, dr, s);
        cover(tc, tr + s, tc + s - 1, tr + s, s);
        cover(tc + s, tr, tc + s, tr + s - 1, s);
        cover(tc + s, tr + s, tc + s, tr + s, s);
    }
    else if (dc < tc + s && dr >= tr + s) //残缺方格位于右上棋盘
    {

        Board[tc + s - 1][tr + s - 1] = t; //覆盖2号三格板
        Board[tc + s][tr + s - 1] = t;
        Board[tc + s][tr + s] = t;
        cover(tc, tr + s, dc, dr, s);
        cover(tc, tr, tc + s - 1, tr + s - 1, s);
        cover(tc + s, tr, tc + s, tr + s - 1, s);
        cover(tc + s, tr + s, tr + s, tc + s, s);
    }
    else if (dc <= tc + s && dr < tr + s) //残缺方格位于左下棋盘
    {

        Board[tc + s - 1][tr + s - 1] = t; //覆盖3号三格板
        Board[tc + s - 1][tr + s] = t;
        Board[tc + s][tr + s] = t;
        cover(tc, tr + s, dc, dr, s);
        cover(tc, tr, tc + s - 1, tr + s - 1, s);
        cover(tc, tr + s, tc + s - 1, tr + s, s);
        cover(tc + s, tr + s, tc + s, tr + s, s);
    }
    else if (dc <= tc + s && dr <= tr + s) //残缺方格位于右下棋盘
    {

        Board[tc + s - 1][tr + s - 1] = t; //覆盖4号三格板
        Board[tc + s - 1][tr + s] = t;
        Board[tc + s][tr + s - 1] = t;
        cover(tc + s, tr + s, dc, dr, s);
        cover(tc, tr, tc + s - 1, tr + s - 1, s);
        cover(tc, tr + s, tc + s - 1, tr + s, s);
        cover(tc + s, tr, tc + s, tr + s - 1, s);
    }
}
void outPutBoard(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%53d ", Board[i][j]);
        printf("\n");
    }
    printf("\n");
}