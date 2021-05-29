#include <stdio.h>
#define FUN(X,Y) 1/(((1/X)+(1/Y))/2) //宏必须大写 不然程序不知道你用的函数还是宏定义
//参数使用的数据类型不当(比如求倒数用了int)会导致A error
int main()
{
    double x,y,z;
    printf("input x,y:\n");
    scanf("%lf",&x);
    scanf("%lf",&y);

    z=FUN(x,y);

    printf("So the result z is %lf\n",z);
    
}