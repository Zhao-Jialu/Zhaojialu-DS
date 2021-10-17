#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode* Tree;
struct TreeNode {
	int val;
	Tree right;
	Tree left;
};
struct TreeNode* CreateTree(int val) {        //树的初始化
	Tree T = (Tree)malloc(sizeof(struct TreeNode));
	T->val = val;
	T->left = NULL;
	T->right = NULL;
}
Tree insert(Tree T, int val) {            //树的插入
	if (T == NULL) {
		T = (Tree)malloc(sizeof(struct TreeNode));
		if (T == NULL) {
			printf("Out of space");
		}
		else {
			T->val = val;
			T->left = NULL;
			T->right = NULL;
		}
	}
	else if (val < T->val) {
		T->left = insert(T->left, val);
	}
	else if (val > T->val) {
		T->right = insert(T->right, val);
	}
	return T;
}
void printTree(Tree T) {
	if (T != NULL) {
		printf("%d\t", T->val);
		printTree(T->left);
		printTree(T->right);
	}
}
int maxDepth(struct TreeNode* root) {
	int left = 1, right = 1;
	if (root == NULL)
		return 0;
	else
	{
		left += maxDepth(root->left);
		right += maxDepth(root->right);
	}
	return left > right ? left : right;//很基础的判断
}


