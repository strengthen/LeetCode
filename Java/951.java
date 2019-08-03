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
    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        if(null == root1 && null == root2) {
            return true;
        }
        
        if(null == root1 || null == root2 || root1.val != root2.val) {
            return false;
        }
        
        return (flipEquiv(root1.left, root2.left) && flipEquiv(root1.right, root2.right)) || (flipEquiv(root1.left, root2.right) && flipEquiv(root1.right, root2.left));
    }
}
__________________________________________________________________________________________________
sample 36584 kb submission
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
    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) {
            return true;
        }
        else if (root1 == null || root2 == null) {
            return false;
        }
        else if (root1.val != root2.val) {
            return false;
        }
        else {
            return (flipEquiv(root1.left, root2.left) && flipEquiv(root1.right, root2.right)) || (flipEquiv(root1.right, root2.left) && flipEquiv(root1.left, root2.right));
        }
    }
}
__________________________________________________________________________________________________
