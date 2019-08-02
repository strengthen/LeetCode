__________________________________________________________________________________________________
0ms
class Solution {
    public TreeNode pruneTree(TreeNode root) {
        if(root==null) return null;
        if( pruneTree(root.left)==null) root.left=null;
        if( pruneTree(root.right)==null) root.right=null;   
        return (root.right==null && root.left==null && root.val==0) ? null : root;        
    }
}
__________________________________________________________________________________________________
sample 35584 kb submission
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
    public TreeNode pruneTree(TreeNode root) {
        if (root == null) return null;
        root.left = pruneTree(root.left);
        root.right = pruneTree(root.right);
        if (root.val == 0 && root.left == null && root.right == null) return null;
        return root;
    }
}
__________________________________________________________________________________________________
