#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL)
        return false;
    if (root->left == NULL && root->right == NULL)
        return targetSum == root->val;
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}
struct TreeNode* CreateNode(int x)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = x;
    node->left = node->right = NULL;
    return node;
}
int main()
{
    struct TreeNode* T1 = CreateNode(1);
    struct TreeNode* T2 = CreateNode(2);
    struct TreeNode* T3 = CreateNode(3);
    T1->left = T2;
    T1->right = T3;
    if (hasPathSum(T1, 3))
        printf("true");
    else
        printf("false");

    if (hasPathSum(T1, 4))
        printf("true");
    else
        printf("false");  

    if (hasPathSum(T1, 1))
        printf("true");
    else
        printf("false");

    return 0;

}
