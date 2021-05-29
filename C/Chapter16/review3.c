#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define RAD PI/180

struct rect
{
    double x;
    double y;
};
struct polar
{
    double p;
    double o;
};
struct rect p_to_r(struct polar* i,struct rect* o);
int main()
{
    struct polar input;
    struct rect output;
    
    puts("Enter the magnitude and angle in degrees:");
    while(scanf("%lf %lf",&input.p,&input.o)==2)
    {
        p_to_r(&input,&output);
        printf("your magnitude and angle: %lf %lf\n",input.p,input.o);
        printf("rectangular coord: x=%lf  y=%lf\n",output.x,output.y);
        printf("Enter next  magnitude and angle in degrees:(q to quit):\n");
    }



}

struct rect p_to_r(struct polar* in,struct rect* out)
{
    out->x=in->p*sin((in->o)*RAD);
    out->y=in->p*cos((in->o)*RAD);
}












