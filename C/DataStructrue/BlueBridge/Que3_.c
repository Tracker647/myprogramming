#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main() {
	int m=3,s=3,n=2;
	int A[3][3]={{2,3,2},{1,0,-1},{1,1,-3}} ,B[3][2]={{0,3},{1,2},{3,1}},C[3][3]={};
	int i,j,k=0;
	
	for(i=0;i<3;i++) 
	{
		for(j=0;j<3;j++)
		{
			C[i][j]=0;
		}
		printf("\n");
	}	
	
	printf("A:\n");
	for(i=0;i<m;i++) 
	{
		for(j=0;j<s;j++)
		{
			printf("%5d",A[i][j]);
		}
		printf("\n");
	}	
	printf("\n");
	
	printf("B:\n");
	for(i=0;i<s;i++) 
	{
		for(j=0;j<n;j++)
		{
			printf("%5d",B[i][j]);
		}
		printf("\n");
	}
	int min = (m<n)?m:n;	
	printf("\n");
	

	
	for(i=0;i<min;i++) 
	{
		for(j=0;j<min+1;j++)
		{
			for(k=0;k<min+1;k++)
			{
				C[i][j]=C[i][j]+(A[i][k]*B[k][j]);
			}		
		}
		
	}
	

	printf("C:\n");
	for(i=0;i<min+1;i++) 
	{
		for(j=0;j<min;j++)
		{
			printf("%5d",C[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	return 0;
}


