#include<stdio.h>
#include<math.h>
#include<string.h>
#define PI 3.1415926
#define size 30

int main()
{
    float l,g,o,s1,s2;
    char c;
    
    printf("input l,g,o:");   
    scanf("%f",&l);
    scanf("%f",&g);
    scanf("%f",&o);

    printf("sin(%.1f)=%f\n",o/2,sin((o/2)*PI/180));

    s1=2*PI*sqrt(l)/sqrt(g);
    s2=s1*(1+(1/4)*pow(sin((o/2)*PI/180),2));

    printf("s1=%f,s2=%f\n",s1,s2);
    printf("y to again,other to quit:");
    while(getchar()!='\n')
        continue;
    c=getchar();

    while(c=='y')
    {     
      

        printf("input l,g,o:");
        scanf("%f",&l);
        scanf("%f",&g);
        scanf("%f",&o);

        printf("sin(%.1f)=%f\n",o/2,sin((o/2)*PI/180));

        s1=2*PI*sqrt(l)/sqrt(g);
        s2=s1*(1+(1/4)*pow(sin((o/2)*PI/180),2));

        printf("s1=%f,s2=%f\n",s1,s2);
        printf("y to again,other to quit:");
        while(getchar()!='\n')
            continue;
        c=getchar();
    }
    printf("\nBye.");
    return 0;
}
