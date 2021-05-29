#include <stdio.h>
#include "circularlist.h"
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	LinkList L1, L2, L3;
	Node *p;

	InitCLinkList(&L1); //一系列初始化
	InitCLinkList(&L2);
	InitCLinkList(&L3);
	int a1[7] = {3, 1, 7, 2, 4, 8, 4};
	int a2[7] = {1, 2, 3, 4, 5, 6, 7};
	int a3[6] = {7, 6, 5, 4, 3, 2};
	int i, k = 1;
	int killed;
	int m1 = 20, n1 = 7;
	int m2 = 4, n2 = 7;
	int m3 = 10, n3 = 6;
	//测试组1
	for (i = 0; a1[i] != NULL; i++)
	{
		InsCLinklist(L1, k++, a1[i]);
	}
	k = 1;
	for (i = 0; i <= 7; i++)
	{
		EnNumber(L1, k++, i);
	}
	p = L1->next;

	ListTraverse(L1);
	printf("\n");
	while (n1 != 0)
	{
		p = Joseph(L1, &m1, &n1, p); //扩展：怎么在函数返回后保留之前的p地址？

		n1 = ListLength(L1);
	}

	i = 1, k = 1;
	printf("\n");
	//测试组2
	for (i = 0; a2[i] != NULL; i++)
	{
		InsCLinklist(L2, k++, a2[i]);
	}
	k = 1;
	for (i = 0; i <= 7; i++)
	{
		EnNumber(L2, k++, i);
	}
	p = L2->next;
	ListTraverse(L2);
	printf("\n");
	while (n2 != 0)
	{
		p = Joseph(L2, &m2, &n2, p); //扩展：怎么在函数返回后保留之前的p地址？
		n2 = ListLength(L2);
	}
	i = 1, k = 1;
	printf("\n");

	//测试组3
	for (i = 0; a3[i] != NULL; i++)
	{
		InsCLinklist(L3, k++, a3[i]);
	}
	k = 1;
	for (i = 0; i <= 6; i++)
	{
		EnNumber(L3, k++, i);
	}
	p = L3->next;

	ListTraverse(L3);
	printf("\n");
	while (n3 != 0)
	{
		p = Joseph(L3, &m3, &n3, p); //扩展：怎么在函数返回后保留之前的p地址？
		n3 = ListLength(L3);
	}

	i = 1, k = 1;
	printf("\n");

	return (0);
}