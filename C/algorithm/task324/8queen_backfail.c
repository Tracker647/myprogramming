#include <stdio.h>
#define N 8
int preboard[N][N] = {0};
int result[N][2] = {0}; //存放各皇后的坐标;
int main()
{
    int myboard[N][N] = {0};

    //棋盘可以是NxN,这里设为8x8
    queen(0, 0, myboard); //从第1个皇后被放在(0,0)开始统计
}
int queen(int col, int row, int *myboard)
{
    int i, j, isend = 0;

    for (row = 0; row < N; row++)
    {

        if ((myboard + col * N)[row] == 0) //这一行可以放皇后！
        {

            for (i = 0; i < N; i++) //保存放皇后前的棋盘布局以便撤回
            {
                for (j = 0; j < N; j++)
                {
                    preboard[i][j] = (myboard + i * N)[j];
                }
            }

            // printf("chessboard before queen %d settled is:\n", col + 1);
            // for (i = 0; i < N; i++)
            // {
            //     for (j = 0; j < N; j++)
            //     {
            //         printf(" %2d ", preboard[i][j]);
            //     }
            //     printf("\n");
            // }

            // setQueen(col,row,board)______________________________
            printf("set queen %d in:(%d,%d)\n", col + 1, col, row);
            for (int k = 0; k < N; k++) //画出皇后在棋盘上的占领区
            {
                (myboard + col * N)[k] = -1; //水平方向
                (myboard + k * N)[row] = -1; //垂直方向

                if (k + (col - row) >= 0 && k + (col - row) <= 7)
                    (myboard + (k + (col - row)) * N)[k] = -1; //左上到右下,(看作 myboard[k+(col-row)][k] 吧,指针看着真繁琐)

                if ((col + row) - k >= 0 && (col + row) - k <= 7)
                    (myboard + k * N)[(col + row) - k] = -1; //右上到左下

                // for (i = 0; i < N; i++)
                // {
                //     for (j = 0; j < N; j++)
                //         printf(" %2d ", (myboard + i * N)[j]);
                //     printf("\n");
                // }
            }
            (myboard + col * N)[row] = col + 1; //放皇后
            result[col][0] = col;               //将皇后的坐标存入结果数组
            result[col][1] = row;
            if (col > 7) //结束条件:到达棋盘第8列
            {
                printf("all 8 queens setted,their location here:\n");
                for (i = 0; i <= 7; i++)
                    printf("queen %d:(%d,%d)\n",i+1,result[i][0], result[i][1]);
                return;
            }

            // printf("chessboard after queen %d settled:\n", col + 1);
            // for (i = 0; i < N; i++)
            // {
            //     for (j = 0; j < N; j++)
            //         printf(" %2d ", (myboard + i * N)[j]);
            //     printf("\n");
            // }
            // printf("\n");
            // ____________________________________________________
            queen(col + 1, row, myboard); //转到下一行放下一个皇后
        }
        // printf("chessboard before queen %d settled is:\n", col + 1);
        // for (i = 0; i < N; i++) //一直到最后列都没放皇后，说明这个结果走不通,回退
        // {
        //     for (j = 0; j < N; j++)
        //     {
        //         printf(" %2d ", preboard[i][j]);
        //     }
        //     printf("\n");
        // }
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                (myboard + i * N)[j] = preboard[i][j];
            }
        }
    }
}