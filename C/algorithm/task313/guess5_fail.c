#include <stdio.h>
typedef struct Student
{
    int guess[5];   //���½��
    int assume;     //ͳ��ÿ�˱�����������Ȳ²�1��²�2
    int *choose[2]; //ÿ�˶��������ж�,�ɽ��жϵĽ������choose�У�������choose��guess�Ƚ��Ƴ�
} Student;
void getResult(Student *guesser);
int guessWho(Student *guesser, int c); //�ҵ��²��ߵĵ�c+1���²�(c=0,1)�µ�����һ����
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
    // ��ʼ��
    for (i = 0; i < 5; i++)
    {
        guesser[i].assume = 0;
        for (j = 0; j < 5; j++)
        {
            guesser[i].guess[j] = setting[i][j]; //���˸��Եľ��½����ʼ��
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
                guesser[i].choose[select++] = &(guesser[i].guess[j]); //���˸��Ե�ѡ�����ָ��������
            }
        }
    }

    getResult(guesser); //���·�������
}
int guessWho(Student *guesser, int c) //�ҵ��²��ߵĵ�c+1���²�(c=0,1)�µ�����һ����
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
        // ��ʼ��
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                guesser[i].guess[j] = setting[i][j]; //���˸��Եľ��½����ʼ��
            }
        }
        for (x = 0; x < 4; x++) //�ж�ÿ�������ߵ��ĸ��²���ȷ��������result��
        {
            i = guessWho(guesser + x, (guesser + x)->assume); //���������x�µ���˭(��i��ʾ)��˭�������ǵڼ�?(��guess[i]��ʾ),��������²���û�б�������ˣ�
            if (result[i] == 0)                               //�������i�����λ�û������
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
        printf("result���:\n");
        printf("a b c d e:\n");
        for (i = 0; i < 5; i++)
        {

            printf("%d ", result[i]);
        }
    }
}