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
public class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new LinkedList<>();
        if (root == null)
            return ans;
        LinkedList<TreeNode> queue = new LinkedList<>();
        boolean reverse = false;
        queue.offer(root);
        while (!queue.isEmpty()) {
            int len = queue.size();
            List<Integer> tempList = new LinkedList<>();
            for (int i = 0; i < len; i++) {
                TreeNode node = queue.poll();
                tempList.add(node.val);
                if (node.left != null)
                    queue.offer(node.left);
                if (node.right != null)
                    queue.offer(node.right);
            }
            if (reverse) {
                Collections.reverse(tempList);
            }
            reverse = !reverse;
            ans.add(tempList);
        }
        return ans;
    }
}
