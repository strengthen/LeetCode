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
    private int tilt = 0;
    public int findTilt(TreeNode root) {
        dfs(root);
        return tilt;
    }
    
    private int dfs(TreeNode node) {
        if(node == null) {
            return 0;
        }
        if(node.left == null && node.right == null) {
            return node.val;
        }
        int sum = 0, valueLeft = 0, valueRight = 0;
        valueLeft += dfs(node.left);
        valueRight += dfs(node.right);
        tilt += valueRight > valueLeft ? valueRight - valueLeft : valueLeft - valueRight;
        sum = valueLeft + valueRight + node.val;
        return sum;
        
    }
}
__________________________________________________________________________________________________
sample 37520 kb submission
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
    private int tilt = 0;
    
    public int findTilt(TreeNode root) {
        helper(root);
        return tilt;
    }
    
    private int helper(TreeNode root) {
        if (root == null)
            return 0;
        int left = helper(root.left);
        int right = helper(root.right);
        tilt += Math.abs(left - right);
        return left + right + root.val;
    }
}
__________________________________________________________________________________________________
