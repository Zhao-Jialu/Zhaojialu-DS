#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
struct TreeNode* insert(int a, int b, int nums[])
{
	if (a >= b)
		return NULL;
	int mid = (a + b) / 2;
	struct TreeNode* T = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	T->val = nums[mid];
	T->left = insert(a, mid, nums);
	T->right = insert(mid + 1, b, nums);
	return T;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
	struct TreeNode* T = insert(0, numsSize, nums);
	return T;
}
void printTree(struct TreeNode* T)
{
	if (T == NULL)
		return NULL;
	printf("%d\t", T->val);
	printTree(T->left);
	printTree(T->right);

}
int main()
{
	int a[5] = {-10,-3,0,5,9 };
	struct TreeNode* T = sortedArrayToBST(a, 5);
	printTree(T);
	return 0;
}
