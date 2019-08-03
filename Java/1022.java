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
    public int sumRootToLeaf(TreeNode root) {
        return dfs(root, 0);
    }
    
    private int dfs(TreeNode root, int val) {
        if (root == null) return 0;
        
        int curr = val * 2 + root.val;
        int l = dfs(root.left, curr);
        int r = dfs(root.right, curr);
        
        if (root.left == null && root.right == null)
            l = curr;
        
        return l + r;
    }
}
__________________________________________________________________________________________________
sample 36732 kb submission
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
    int sum = 0;
    public int sumRootToLeaf(TreeNode root) {
        sumRootToLeaf(root, "");
        return sum;
    }
    
    public void sumRootToLeaf(TreeNode root, String s) {
        if (root==null) return;
        if (root.right==null&&root.left==null) {
            int x = Integer.parseInt(s+root.val, 2);
            sum+=x;
            return;
        }
        sumRootToLeaf(root.left, s+root.val);
        sumRootToLeaf(root.right, s+root.val);
    }
}
__________________________________________________________________________________________________
