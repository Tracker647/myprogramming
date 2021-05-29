#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int c(int k, int n);
int A(int k,int n);
int fac(int n);
int A(int k,int n)
{
	int a,b,s;
	a=fac(n);
	b=fac(n-k);
	s=a/b;
	printf("A(%d,%d)=%d\n",k,n,s);
	return s;
}

int c(int k, int n)
{
	int s, a, b;
	a = A(k,n);
	b = fac(k);
	s = a / b;
	return s;
}

int fac(int n)
{
	if(n>=1)
		return n*fac(n-1);
	else
		return 1;		
}

int main()
{

	int k = 3, n = 10, s,f;
	s = c(k,n);
	printf("c(%d,%d)=%d",k,n,s);	
	return 0;
}

