__________________________________________________________________________________________________
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
    double res = 0;
    public double maximumAverageSubtree(TreeNode root) {
        solve(root);
        return res;
    }
    
    int[] solve(TreeNode root) {
        int[] res = new int[2];
        res[0] = 1;
        res[1] = root.val;
        if (root.left != null) {
            int[] tmp = solve(root.left);
            res[0] += tmp[0];
            res[1] += tmp[1];
        }
        if (root.right != null) {
            int[] tmp = solve(root.right);
            res[0] += tmp[0];
            res[1] += tmp[1];
        }
        
        this.res = Math.max(this.res, 1.0 * res[1] / res[0]);
        return res;
    }
}

__________________________________________________________________________________________________

__________________________________________________________________________________________________
