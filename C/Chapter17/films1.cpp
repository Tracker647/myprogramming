/*filmsl.c--ʹ��һ���ṹ����*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45 /*����Ƭ���������С*/

struct film
{
    char title[TSIZE];
    int rating;
};
char *s_gets(char *str, int n);

int main(void)
{
    int i = 0;
    int j;
    int FMAX; /*ӰƬ���������*/

    struct film *movies;

    printf("How many movies your watched?");
    scanf("%d", &FMAX);
    fflush(stdin);
    movies = (struct film *)malloc(FMAX * sizeof(struct film));

    puts("Enter first movie title:");
    while (i < FMAX && s_gets(movies[i].title, TSIZE) != NULL &&
           movies[i].title[0] != '\0')
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &movies[i++].rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop):");
    }
    if (i == 0)
        printf("No data entered.");
    else
        printf("Here is the movie list:\n");

    for (j = 0; j < i; j++)
        printf("Movie:%s Rating:%d\n", movies[j].title, movies[j].rating);
    printf("Bye!\n");
    free(movies);
    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); //���һ��з�
        if (find)                //�����ַ����NOLL��
            *find = '\0';        //�ڴ˴�����һ�����ַ�
        else
            while (getchar() != '\n')
                continue; //����ʣ��������
    }

    return ret_val;
}