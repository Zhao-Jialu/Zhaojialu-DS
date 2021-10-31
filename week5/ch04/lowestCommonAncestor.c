#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	
};
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if ((root->val - p->val) * (root->val - q->val) <= 0)
        return root;
    if ((root->val < p->val) && (root->val < q->val))
        return lowestCommonAncestor(root->right, p, q);
    else
        return lowestCommonAncestor(root->left, p, q);
}
struct TreeNode* insert(struct TreeNode* T,int x)
{
    if (T == NULL)
    {
        T = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        T->val = x;
        T->left = T->right = NULL;
    }
    else if (x > T->val)
        T->right = insert(T->right,x);
    else if (x < T->val)
        T->left = insert( T->left,x);
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
    struct TreeNode* T=NULL;
    T = insert(T, 5);
    T = insert(T, 3);
    T = insert(T, 2);
    T = insert(T, 4);
    T = insert(T, 1);
    T = insert(T, 6);
    printTree(T);
    struct TreeNode* p1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* p2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p1->val = 1;
    p2->val = 4;
    struct TreeNode* p = lowestCommonAncestor(T, p1,p2);
    
    printf("\n%d", p->val);
}
