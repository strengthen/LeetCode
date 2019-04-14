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
   public int maxAncestorDiff(TreeNode root) {
        return dfs(root, root.val, root.val);
    }

    public int dfs(TreeNode root, int mx, int mn) {
        if (root == null) return 0;
        int res = Math.max(mx - root.val, root.val - mn);
        mx = Math.max(mx, root.val);
        mn = Math.min(mn, root.val);
        res = Math.max(res, dfs(root.left, mx, mn));
        res = Math.max(res, dfs(root.right, mx, mn));
        return res;
    }
}