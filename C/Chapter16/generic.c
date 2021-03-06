#include<stdio.h>
#include <math.h>
#define RAD_TO_DEG (180/(4*atanl(1)))

//泛型平方根函数
#define SQRT(X) _Generic((X),\
    long double: sqrtl,\
    default:     sqrt,\
    float:       sqrtf)(x)


//泛型正弦函数，角度的单位为度
#define SIN(X) _Generic((X),\
    long double: sinl((X)/RAD_TO_DEG),\
    default:    sin((X)/RAD_TO_DEG),\
    float:       sinf((X)/RAD_TO_DEG)\
)
int main()
{
    float x=45.0f;
    float xx=45.0;
    long double xxx=45.0L;

    long double y = SQRT(x);
    long double yy = SQRT(xx);
    long double yyy = SQRT(xxx);
    printf("%.17lf\n",y);   //匹配float
    printf("%.17f\n",yy);  //匹配default                   
    printf("%.17lf\n",yyy); //匹配long double
    int i=45;
    yy=SQRT(i);
    printf("%.17lf\n",yy);
    yyy = SIN(xxx);
    printf("%.17lf\n",yyy);

    return 0;
}