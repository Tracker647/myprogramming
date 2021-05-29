#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main()
{
	LinkList LA, LB, LC;
	int i, j, k = 1, flag = 1;
	int a[10] = {5, 10, 20, 15, 25, 30}, b[10] = {5, 15, 35, 25};
	Initlist(&LA);
	Initlist(&LB);
	Initlist(&LC);
	
	for (i = 0; a[i] != NULL; i++, k++) 
		InsList(LA, k, a[i]);

	k = 1;
	for (i = 0; b[i] != NULL; i++, k++) 
		InsList(LB, k, b[i]);

	ListTraverse(LA);
	ListTraverse(LB);

	// MergeLinkList(LA, LB, LC);
	// ListTraverse(LC);

	LC = Different(LA, LB, LC);
	ListTraverse(LC);
	return 0;
}