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
    private boolean flag = true;

    public boolean isBalanced(TreeNode root) {
       height(root);
       return flag;
    }

public int height(TreeNode root) {
    if (root == null)
        return 0;
    if(!flag){
        return 0;
    }
    int l = height(root.left);
    int r = height(root.right);
    if (Math.abs(l - r) > 1){
        flag = false;
        return 0;
    }
    return 1 + Math.max(l, r);
}
}
__________________________________________________________________________________________________
sample 34472 kb submission
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
    
    private boolean ans = true;
    
    public boolean isBalanced(TreeNode root) {
        solve(root);
        return ans;
    }
    
    private int solve(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int left = solve(root.left);
        int right = solve(root.right);
        if(Math.abs(left - right) > 1) {
            ans = false;
        }
        return 1 + Math.max(left, right);
    }
}
__________________________________________________________________________________________________
