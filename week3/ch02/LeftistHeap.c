#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode* TreeNode;
struct TreeNode {
	int Element; //节点上的值
	TreeNode left;  //左节点
	TreeNode right; //右节点
	int Npl;  //零路径长
};

TreeNode Merge(TreeNode H1, TreeNode H2) {  //合并左式堆的驱动例程
	if (H1 == NULL) 
		return H2;
	if (H2 == NULL)
		return H1;
	if (H1->Element < H2->Element)
		return Merge1(H1, H2);
	else
		return Merge1(H2, H1);
}
static TreeNode Merge1(TreeNode H1, TreeNode H2) {   //合并左式堆的实际例程
	if (H1->left = NULL)
		H1->left = H2;
	else
	{
		H1->right = Merge(H1->right, H2);
		if (H1->left->Npl < H1->right->Npl)
			SwapChildren(H1);

		H1->Npl = H1->right->Npl + 1;
	}
	return H1;
}

TreeNode Insert1(int x, TreeNode H) {
	TreeNode SingleNode;
	SingleNode = (TreeNode)malloc(sizeof(struct TreeNode));
	SingleNode->Element = x;
	SingleNode->Npl = 0;
	SingleNode->left = SingleNode->right = NULL;
	H = Merge(H, SingleNode);
}

TreeNode DeleteMin(TreeNode H) {
	TreeNode leftHeap, rightHeap;
	leftHeap = H->left;
	rightHeap = H->right;
	free(H);
	return Merge(leftHeap, rightHeap);
}
