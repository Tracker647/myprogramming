#include <stdio.h>
int arr[7][7];
int i,j,k = 1;
// int drawCircle(int r, int *edge); //用于画"环"的函数，接受环的序号，环长和要画环的数组，一次画一圈
int main()
{
    int n = 7, i = 0, j = 0, r = 1;
    int round = (n + 1 / 2);    //要向上取整，故被除数加1
    int edge = n - 1;

    for (r = 1; r < round; r++)
    {
        drawCircle(r, edge); //随着环次数递增，环的长度逐渐减小
        edge = edge - 2;
        if(edge == 0 && (n % 2))       //矩阵阶数为奇数时最后一个环是一个数，edge取1
        {
            edge = 1;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%5d ", arr[i][j]);
        }
        printf("\n");
    }
}

int drawCircle(int r, int edge)
{
    
    //按顺时针画圈，每次从一个角点画到另一个角点前
    for (j = (r - 1); j <= (r + edge - 2); j++) //向右
        arr[i][j] = k++;
    for (i = (r - 1); i <= (r + edge - 2); i++) //向下
        arr[i][j] = k++;
    for (j = (r + edge - 1); j >= r; j--) //向左
        arr[i][j] = k++;
    for (i = (r + edge - 1); i >= r; i--) //向上
        arr[i][j] = k++;

    i++;j++;    //画圈完会回到原点，因此还要再右下移一格进入下一个角点
}