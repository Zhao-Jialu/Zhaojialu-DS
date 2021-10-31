#include<stdio.h>
 struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    
};

void sort(struct TreeNode* root, int* res, int* len)
{
    if (root == NULL)
        return;
    res[(*len)++] = root->val;
    sort(root->left, res, len);
    sort(root->right, res, len);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {  //前序遍历
    int* res = (int*)malloc(sizeof(int) * 2000);
    *returnSize = 0;
    sort(root, res, returnSize);
    return res;
}


void sort_1(struct TreeNode* root, int* res, int* len)
{
    if (root == NULL)
        return;
    sort_1(root->left, res, len);
    sort_1(root->right, res, len);
    res[(*len)++] = root->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {  // 后序遍历
    int* res = (int*)malloc(sizeof(int) * 2000);
    *returnSize = 0;
    sort(root, res, returnSize);
    return res;
}
