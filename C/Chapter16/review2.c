#include <stdio.h>
#define FUN(X,Y) 1/(((1/X)+(1/Y))/2) //������д ��Ȼ����֪�����õĺ������Ǻ궨��
//����ʹ�õ��������Ͳ���(������������int)�ᵼ��A error
int main()
{
    double x,y,z;
    printf("input x,y:\n");
    scanf("%lf",&x);
    scanf("%lf",&y);

    z=FUN(x,y);

    printf("So the result z is %lf\n",z);
    
}