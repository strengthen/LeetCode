__________________________________________________________________________________________________
sample 2 ms submission
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

    int maxLen = 0;
    public int longestUnivaluePath(TreeNode root) {
        if (root == null) return 0;
        helper(root);
        return maxLen;
    }
    
    public int helper(TreeNode root) {
        if (root == null) return 0;
        if (root.left==null && root.right == null) return 0;
        
        //children result
        int self = 0;
        int left = helper(root.left);
        int right = helper(root.right);
        
        if (root.left!=null && root.left.val==root.val) {
            if (root.right!=null && root.right.val==root.val) {
                self = Math.max(left,right) + 1;
                maxLen = Math.max(maxLen, left + right + 2);
            } else {
                self = left + 1;
                maxLen = Math.max(maxLen, self);
            }
        } else {
            if (root.right!=null && root.right.val==root.val) {
                self = right + 1;
                maxLen = Math.max(maxLen, self);
            } else {
                //do nothing
            }
        }
        return self;
    }    
}
__________________________________________________________________________________________________
sample 42204 kb submission
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
    private int max = 0;

    public int longestUnivaluePath(TreeNode root) {
        pathHelper(root, -1);
        return max;
    }

    private int pathHelper(TreeNode root, int parent) {
        if (root == null)
            return 0;

        int left = pathHelper(root.left, root.val);
        int right = pathHelper(root.right, root.val);

        max = Math.max(max, left + right);

        return root.val == parent ? Math.max(left, right) + 1 : 0;
    }
}
__________________________________________________________________________________________________
