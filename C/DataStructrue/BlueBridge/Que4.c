#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
compare(const void *a,const void *b)
{
	return ( (*(int*)a) > (*(int*)b) ) ? 1 : -1;
}

ltorkth(int l,int r,int k,int *arr)
{
	int ltor[r];
	int i;
	for(i=0;i<r;i++)
	{
		ltor[i]=arr[i];
	}
	qsort(ltor,r,sizeof(int),compare);
	
	return ltor[k-1];
}

int main() {
	int i,m,r,k;
	int kth;
	int arr[5]={1,5,2,4,3};
	printf("���г�%d\n",sizeof(arr)/sizeof(arr[0]) );
	printf("����Ϊ:\n");
	for(i=0;arr[i]!='\000';i++)
	{
		printf(" %d",arr[i]);
	}
	printf("\n");
//	for(i=0;i<m;i++)
//	{
	r=3,k=2; //����r,k 
	kth = ltorkth(1,r,k,arr);
		
//	}
	printf("�ӵ�1��������%d�����У���%d�������:%d",r,k,kth);
	return 0;
}
