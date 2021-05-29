#include<stdio.h>
#include <math.h>
#define RAD_TO_DEG (180/(4*atanl(1)))

//����ƽ��������
#define SQRT(X) _Generic((X),\
    long double: sqrtl,\
    default:     sqrt,\
    float:       sqrtf)(x)


//�������Һ������Ƕȵĵ�λΪ��
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
    printf("%.17lf\n",y);   //ƥ��float
    printf("%.17f\n",yy);  //ƥ��default                   
    printf("%.17lf\n",yyy); //ƥ��long double
    int i=45;
    yy=SQRT(i);
    printf("%.17lf\n",yy);
    yyy = SIN(xxx);
    printf("%.17lf\n",yyy);

    return 0;
}