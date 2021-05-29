#include <stdio.h>
void hanoi(int n, char a, char b, char c);
int main()
{
    int n;
    printf("ÊäÈëËþµÄ½×Êý:\n");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
}
void hanoi(int n, char a, char b, char c)
{
    if (n > 0)
    {
        hanoi(n - 1, a, c, b);
        printf("Move dish %d a pile %c to %c\n", n, a, b);
        hanoi(n - 1, c, b, a);
    }
}