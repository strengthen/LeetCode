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
    
    int min = Integer.MAX_VALUE;
    TreeNode pre;
    public int getMinimumDifference(TreeNode root) {
    	findMin(root);
    	return min;
    }
    
    private void findMin(TreeNode root) {
    	if(root == null) return;
        getMinimumDifference(root.left);
        if(pre != null)  min = Math.min(min, Math.abs(root.val - pre.val));
        pre = root;
        getMinimumDifference(root.right);        
    }
}
__________________________________________________________________________________________________
sample 37744 kb submission
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
    Integer ans;
    public int getMinimumDifference(TreeNode root) {
        ans = Integer.MAX_VALUE;
        helper(root, null, null);
        return ans;
    }
    
    // non-negative values
    public void helper(TreeNode root, Integer max, Integer min) {
        if(root==null) return ;
        helper(root.left, root.val, min);
        if(max!=null) ans = Math.min(ans, Math.abs(max-root.val));
        if(min!=null) ans = Math.min(ans, Math.abs(root.val-min));
        helper(root.right, max, root.val);
    }
}
__________________________________________________________________________________________________
