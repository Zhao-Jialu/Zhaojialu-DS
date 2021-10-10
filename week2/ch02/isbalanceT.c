#include <stdio.h>
#include<math.h>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

};

int getDepth(struct TreeNode* root) {//得到二叉树的深度;
    if (root == NULL)
        return 0;

    return fmax(getDepth(root->left), getDepth(root->right)) + 1;
}


bool isBalanced(struct TreeNode* root) {


    if (root == NULL || (root->left == NULL && root->right == NULL))//当到达叶子结点时候
        return true;

    if (abs(getDepth(root->left) - getDepth(root->right)) > 1)  //abs()取绝对值
        return false;

    return isBalanced(root->left) && isBalanced(root->right);//递归检查左右子树;
}
