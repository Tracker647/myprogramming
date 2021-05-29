#include <stdio.h>
typedef struct Student
{
    int guess[5];   //竞猜结果
    int assume;     //统计每人被假设次数，先猜测1后猜测2
    int *choose[2]; //每人都有两个判断,可将判断的结果放入choose中，名次由choose和guess比较推出
} Student;
void getResult(Student *guesser);
int guessWho(Student *guesser, int c); //找到猜测者的第c+1个猜测(c=0,1)猜的是哪一个人
int main()
{
    Student guesser[5];
    int a = 0, b = 1, c = 2, d = 3, e = 4;
    int i, j, flag = 0;
    int result[5];
    int setting[5][5] = {
        {0, 3, 5, 0, 0},
        {0, 0, 0, 2, 4},
        {0, 1, 0, 0, 4},
        {0, 2, 1, 0, 0},
        {3, 0, 0, 2, 0}};
    // 初始化
    for (i = 0; i < 5; i++)
    {
        guesser[i].assume = 0;
        for (j = 0; j < 5; j++)
        {
            guesser[i].guess[j] = setting[i][j]; //五人各自的竞猜结果初始化
        }
    }
    int select;
    for (i = 0; i < 5; i++)
    {
        select = 0;
        for (j = 0; j < 5; j++)
        {
            if (guesser[i].guess[j] != 0)
            {
                guesser[i].choose[select++] = &(guesser[i].guess[j]); //五人各自的选择放入指针数组中
            }
        }
    }

    getResult(guesser); //竞猜分析函数
}
int guessWho(Student *guesser, int c) //找到猜测者的第c+1个猜测(c=0,1)猜的是哪一个人
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (guesser->guess[i] == *(guesser->choose[c]))
        {
            return i;
        }
    }
}
void getResult(Student *guesser)
{
    int x, i, j, other, flag = 0;
    int result[5] = {0};
    int sum = 0;
    if (sum != 15)
    {
        sum = 0;
        int setting[5][5] = {
            {0, 3, 5, 0, 0},
            {0, 0, 0, 2, 4},
            {0, 1, 0, 0, 4},
            {0, 2, 1, 0, 0},
            {3, 0, 0, 2, 0}};
        // 初始化
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                guesser[i].guess[j] = setting[i][j]; //五人各自的竞猜结果初始化
            }
        }
        for (x = 0; x < 4; x++) //判断每个竞猜者的哪个猜测正确，并放入result中
        {
            i = guessWho(guesser + x, (guesser + x)->assume); //这个竞猜者x猜的是谁(用i表示)？谁的名次是第几?(用guess[i]表示),他的这个猜测有没有被假设过了？
            if (result[i] == 0)                               //如果对于i的名次还没被假设
            {
                result[i] = (guesser + x)->guess[i];
                for (other = 0; other < 4; other++)
                {
                    if (other != x)
                    {
                        (guesser + other)->guess[i] = 0;
                    }
                }
            }

            (guesser + x)->assume++;
        }
        for (i = 0; i < 4; i++)
        {
            sum += result[i];
        }
    }
    else
    {
        printf("result结果:\n");
        printf("a b c d e:\n");
        for (i = 0; i < 5; i++)
        {

            printf("%d ", result[i]);
        }
    }
}