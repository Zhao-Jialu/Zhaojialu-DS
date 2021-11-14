#include<stdio.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    
};
int* arr;
int arrsize;
int count, countmax, base;
void update(int x) {
    if (x == base)
        count++;
    else {
        count = 1;
        base = x;
    }
    if (count == countmax)
        arr[arrsize++] = base;
    if (count > countmax) {
        countmax = count;
        arrsize = 0;
        arr[arrsize++] = base;
    }

}
void dfs(struct TreeNode* root) {
    if (root == NULL)
        return;
    dfs(root->left);
    update(root->val);
    dfs(root->right);
}
int* findMode(struct TreeNode* root, int* returnSize) {
    if (root == NULL)
        return;
    arr = (int*)malloc(sizeof(int) * 4001);
    arrsize = count = countmax = base = 0;
    dfs(root);
    *returnSize = arrsize;
    return arr;
}
