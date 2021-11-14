#include<stdio.h>
 struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* mirrorTree(struct TreeNode* root) {
    if (!root)
        return NULL;
    struct TreeNode* root1;
    root1 = root->left;
    root->left = root->right;
    root->right = root1;
    mirrorTree(root->left);
    mirrorTree(root->right);
    return root;
}
