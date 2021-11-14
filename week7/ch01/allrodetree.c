#include<stdio.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    
};
static char** path;
static int pathsize;
void getpath(struct TreeNode* root, int top, int a[]) {
    char* tmp = (char*)malloc(1001);
    int len = 0;
    if (root->left == NULL && root->right == NULL)//节点是叶子节点，将路径加入path数组
    {
        for (int i = 0; i < top; i++)
        {
            len += sprintf(tmp + len, "%d->", a[i]);
        }
        sprintf(tmp + len, "%d", root->val);
        path[pathsize++] = tmp;
    }
    else {                          //节点不是叶子节点，继续向下遍历
        a[top++] = root->val;
        if (root->left)
            getpath(root->left, top, a);
        if (root->right)
            getpath(root->right, top, a);
    }

}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    path = (char**)malloc(sizeof(char*) * 100);
    pathsize = 0;
    int top = 0;
    int a[1001];
    getpath(root, top, a);
    *returnSize = pathsize;
    return path;
}
