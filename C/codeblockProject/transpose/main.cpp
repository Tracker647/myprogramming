#include <stdio.h>
int main()
{
    int i,j,sum=0;
    int a[3][2] = {{1,2},{4,5},{7,8}};
    for(i=0;i<3;i++)
            for(j=0;j<2;j++)
                sum+= a[j][i];
    printf("%d",sum);
    return 0;
}
