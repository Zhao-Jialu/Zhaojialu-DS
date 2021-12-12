class Solution {
    public int max(int a, int b)
     {
    if(a>b)
    return a;
    else
    return b;
    }
    public int maxDepth(TreeNode root){
    if(root==null)
    return 0;
    return max(maxDepth(root.left),maxDepth(root.right))+1;
}
}
