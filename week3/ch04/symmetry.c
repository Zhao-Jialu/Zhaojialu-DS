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
int symmetric(struct TreeNode* L, struct TreeNode* R) {
	if (R == NULL && L == NULL)
		return 1;
	if (R == NULL || L == NULL || R->val != L->val)
		return 0;

	return symmetric(L->left, R->right) && symmetric(R->left, L->right);
}

int isSymmetric(struct TreeNode* root) {
	if (root == NULL)
		return 1;

	return symmetric(root->left, root->right);
}
