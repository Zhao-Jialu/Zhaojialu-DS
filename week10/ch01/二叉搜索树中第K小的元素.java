/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int result=-1;
    int count=0;
    public int kthSmallest(TreeNode root, int k) {
        count=k;
        order(root);
        return result;
    }
public void order(TreeNode root){
    if(root==null)
    return;
    order(root.left);
    if(--count==0){
    result=root.val;
    return;
    }
    order(root.right);
}
}
