#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	double x,a,i=2,s=0;

	printf("����x��x=0)�˳���\n"); 
	scanf("%lf",&x);
	while(getchar()!='\n')
	{
		continue;
	}
	while(x!=0)
	{
		while(s<x)
		{
			a = 1/i;
			s=s+a;
			i++;
		}
		
		printf("%d card(s)\n",s);
		printf("����x��x=0)�˳���\n"); 
		scanf("%lf",&x);
		while(getchar()!='\n')
		{
			continue;
		}
		i=2,s=0;
	} 
	
	return 0;
}
