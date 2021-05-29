#include <stdio.h>
#define N 8
int preboard[N][N] = {0};
int result[N][2] = {0}; //��Ÿ��ʺ������;
int main()
{
    int myboard[N][N] = {0};

    //���̿�����NxN,������Ϊ8x8
    queen(0, 0, myboard); //�ӵ�1���ʺ󱻷���(0,0)��ʼͳ��
}
int queen(int col, int row, int *myboard)
{
    int i, j, isend = 0;

    for (row = 0; row < N; row++)
    {

        if ((myboard + col * N)[row] == 0) //��һ�п��ԷŻʺ�
        {

            for (i = 0; i < N; i++) //����Żʺ�ǰ�����̲����Ա㳷��
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
            for (int k = 0; k < N; k++) //�����ʺ��������ϵ�ռ����
            {
                (myboard + col * N)[k] = -1; //ˮƽ����
                (myboard + k * N)[row] = -1; //��ֱ����

                if (k + (col - row) >= 0 && k + (col - row) <= 7)
                    (myboard + (k + (col - row)) * N)[k] = -1; //���ϵ�����,(���� myboard[k+(col-row)][k] ��,ָ�뿴���深��)

                if ((col + row) - k >= 0 && (col + row) - k <= 7)
                    (myboard + k * N)[(col + row) - k] = -1; //���ϵ�����

                // for (i = 0; i < N; i++)
                // {
                //     for (j = 0; j < N; j++)
                //         printf(" %2d ", (myboard + i * N)[j]);
                //     printf("\n");
                // }
            }
            (myboard + col * N)[row] = col + 1; //�Żʺ�
            result[col][0] = col;               //���ʺ���������������
            result[col][1] = row;
            if (col > 7) //��������:�������̵�8��
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
            queen(col + 1, row, myboard); //ת����һ�з���һ���ʺ�
        }
        // printf("chessboard before queen %d settled is:\n", col + 1);
        // for (i = 0; i < N; i++) //һֱ������ж�û�Żʺ�˵���������߲�ͨ,����
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