__________________________________________________________________________________________________
sample 0 ms submission
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int diameterOfBinaryTree(TreeNode root) {
        int[] max = new int[1];
        dfs(root, max);
        return max[0];
    }
    
    private int dfs(TreeNode node, int[] max) {
        if (node == null) return 0;
        int l = dfs(node.left, max);
        int r = dfs(node.right, max);
        max[0] = Math.max(max[0], l + r);
        return Math.max(l, r) + 1;
    }
}
__________________________________________________________________________________________________
sample 37108 kb submission
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int diameterOfBinaryTree(TreeNode root) {
        int[] ans = new int[1];
        dfsHelper(root, ans);
        return ans[0];
    }
    private int dfsHelper(TreeNode root, int[] ans) {
        if (root == null) return -1;
        int left = dfsHelper(root.left, ans);
        int right = dfsHelper(root.right, ans);
        if (left == -1 && right == -1) {
            return 0;
        } else if (left == -1) {
            ans[0] = Math.max(ans[0], 1 + right);
        } else if (right == -1) {
            ans[0] = Math.max(ans[0], 1 + left);
        } else {
            ans[0] = Math.max(ans[0], 1 + left + 1 + right);
        }
        return 1 + Math.max(left, right);
    }
}
__________________________________________________________________________________________________
