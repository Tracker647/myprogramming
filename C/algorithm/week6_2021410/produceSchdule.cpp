#include <bits/stdc++.h>
using namespace std;
struct node
{
    int a, b, flag;
} item[1010];
bool cmp(node x, node y)
{
    if (x.flag == y.flag)
    {
        if (x.flag == 0)
            return x.a < y.a;
        return x.b > y.b;
    }
    return x.flag < y.flag;
}
int main()
{
    int n = 6;
    int print[6] = {3, 12, 5, 2, 9, 11};
    int deco[6] = {8, 10, 9, 6, 3, 1};
    for (int i = 0; i < n; i++)
        item[i].a = print[i];
    for (int i = 0; i < n; i++)
        item[i].b = deco[i];
    for (int i = 0; i < n; i++)
        item[i].flag = (item[i].a < item[i].b ? 0 : 1);
    sort(item, item + n, cmp);
    int A = 0, B = 0;
    for (int i = 0; i < n; i++)
    {
        A += item[i].a;
        B = max(B, A) + item[i].b;
    }
    printf("%d\n", B);
}