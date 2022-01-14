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
   public TreeNode buildTree(int[] preorder, int[] inorder) {
    List<Integer> preorderList = new ArrayList<>();
    List<Integer> inorderList = new ArrayList<>();
    for (int i = 0; i < preorder.length; i++) {
        preorderList.add(preorder[i]);
        inorderList.add(inorder[i]);
    }
    return helper(preorderList, inorderList);
}

private TreeNode helper(List<Integer> preorderList, List<Integer> inorderList) {
    if (inorderList.size() == 0)
        return null;
    int rootVal = preorderList.remove(0);
    TreeNode root = new TreeNode(rootVal);
    int mid = inorderList.indexOf(rootVal);
    root.left = helper(preorderList, inorderList.subList(0, mid));
    root.right = helper(preorderList, inorderList.subList(mid + 1, inorderList.size()));
    return root;
}
}
