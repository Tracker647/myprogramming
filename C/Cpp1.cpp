/*�������������ӡ����*/
#pragma once
#include<stdio.h>
#include<vector>
#include<math.h>
#include<malloc.h>

// ��������ֵ�����ֵ��Ԫ�ؽ�����Ϊ�������еĿսڵ�
#define numMeansNull -1

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ��nums�������ɶ�����������Ԫ����ΪС�ڵ���999�����������սڵ��Ժ궨��numMeansNull��ʾ��
struct TreeNode *createTreeFromArray(int *nums, int numsSize);
// ��ӡ������bt
void bt_print(TreeNode *bt);





void calTreeDepth(TreeNode *t);
void setPrintBuffer(TreeNode *t);

// �ɶ�ά�������ɶ�����
struct TreeNode *createTreeFromArray(int *nums, int numsSize) {
	struct TreeNode *nodes = (struct TreeNode*)calloc(numsSize, sizeof(struct TreeNode));
	for (int i = 0; i < numsSize; i++) {
		nodes[i].val = nums[i];
		int child = i * 2 + 1;
		nodes[i].left = (child < numsSize && nums[child] != numMeansNull) ? &nodes[child] : NULL;
		child = i * 2 + 2;
		nodes[i].right = (child < numsSize && nums[child] != numMeansNull) ? &nodes[child] : NULL;
	}
	return &nodes[0];
}

// ��ǰ�ڵ�����
int depth = 0;
// ��������ȣ����ֻ�и��ڵ������Ϊ1
int depthMax = 0;
// ��ӡ�������Ŀ�ȣ���ǰӦ��ӡ���������ϴδ�ӡλ�õ�����
int width = 0, column = 0, lastColumn = 0;
char **printBuffer = NULL;

void bt_print(TreeNode *bt) {
	depth = 0;
	column = 0;
	lastColumn = 0;
	depthMax = 0;
	// �������Ĵ�С�����ڴ�
	calTreeDepth(bt);
	width = 3 * ((1 << (depthMax - 1)) * 2 - 1);
	int height = 1 + (depthMax - 1) * 3;
	printBuffer = (char**)malloc(height *sizeof(char*));
	for (int i = 0; i < height; i++) {
		printBuffer[i] = (char*)malloc(width * sizeof(char));
		memset(printBuffer[i],' ',width);
		printBuffer[i][width - 1] = '\0';
	}

	depth = 0;
	column = width / 2;
	lastColumn = column;
	setPrintBuffer(bt);
	for ( i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%c", printBuffer[i][j]);
		}
		printf("\n");
	}

}

// �ݹ��ҵ�������������
void calTreeDepth(TreeNode *t) {
	if (t) {
		depth++;
		depthMax = depthMax < depth ? depth : depthMax;
		calTreeDepth(t->left);
		calTreeDepth(t->right);
		depth--;
	}
}

// ������������������õ���ӡ������
void setPrintBuffer(TreeNode *t) {
	if (t) {
		depth++;

		int val = t->val;
		for (int i = 0; i < 3; i++) {
			printBuffer[(depth - 1) * 3][column+1-i] = val%10 + 0x30;
			val /= 10;
		}
		if (depth > 1) {
			int linkLineInterval =  (column- lastColumn)/3;
			char linkChar = linkLineInterval > 0 ? '\\' : '/';
			printBuffer[(depth - 1) * 3 - 1][column - linkLineInterval] = linkChar;
			printBuffer[(depth - 1) * 3 - 2][column - 2*linkLineInterval] = linkChar;
		}
		
		int step = (1<<(depthMax-depth-1))*3;

		lastColumn = column;
		column -= step;
		setPrintBuffer(t->left);
		column += step;

		lastColumn = column;
		column += step;
		setPrintBuffer(t->right);
		column -= step;
		depth--;
	}
}



int main() {
	int nums[] = { 15,54,87,1,45,20,4,88,452,-1,-1,13,-1,150,5, 6,-1,3,4,5,6,7,8,9,-1,11,12,13,14,15,16 };
	struct TreeNode* root = createTreeFromArray(nums, sizeof(nums) / sizeof(nums[0]));
	bt_print(root);
	getchar();
	return 0;
}
