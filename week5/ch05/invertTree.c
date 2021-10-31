#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
        return root;
    struct TreeNode* p = root->right;
    root->right = invertTree(root->left);
    root->left = invertTree(p);
    return root;
}
struct TreeNode* CreateNode(int x)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = x;
    node->left = node->right = NULL;
    return node;
}
void printTree(struct TreeNode* root)
{
    if (root == NULL)
        return;
    printf("%d\t", root->val);
    printTree(root->left);
    printTree(root->right);
}
int main()
{
    struct TreeNode* root1 = CreateNode(1);
    struct TreeNode* root2 = CreateNode(2);
    struct TreeNode* root3 = CreateNode(3);
    root1->left = root2;
    root1->right = root3;
    printTree(root1);
    root1 = invertTree(root1);
    printf("\n");
    printTree(root1);
}
