#include<stdlib.h>
#include<stdio.h>
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
int* arr;
int arrsize;
void getarr(struct TreeNode* root) {
    if (!root)
        return;
    getarr(root->left);
    arr[arrsize++] = root->val;
    getarr(root->right);
}
int getmin()
{
    int min;
    min = abs(arr[1] - arr[0]);
    for (int i = 2; i < arrsize; i++)
    {
        int tmp = abs(arr[i] - arr[i - 1]);
        if (tmp < min)
            min = tmp;
    }
    return min;
}
int getMinimumDifference(struct TreeNode* root) {
    arr = (int*)malloc(sizeof(int) * 10000);
    arrsize = 0;
    getarr(root);
    int a = getmin();
    return a;
}
