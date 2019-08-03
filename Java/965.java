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
    
    TreeNode prev = null;
    public boolean isUnivalTree(TreeNode root) {
        
        if(root == null)
            return true;
        
        if(prev != null){
           if(prev.val != root.val)
            return false; 
        }
           
        
        prev = root;
        if(isUnivalTree(root.left) && isUnivalTree(root.right)){
           return true; 
        }
        
        return false;
    }
}
__________________________________________________________________________________________________
sample 35488 kb submission
// Base case root = null
// Let left be val of left node. If left node is null, left = root.val
// Let right be val of right node. If right node is null, right = root.val
// Return root.val = left && root.val == root.right && isValid(root.left) && isValid(root.right) 

class Solution {
    public boolean isUnivalTree(TreeNode root) {
        if (root == null) return true;
        int left = (root.left == null) ? root.val : root.left.val;
        int right = (root.right == null) ? root.val : root.right.val;
        return root.val == left && root.val == right && isUnivalTree(root.left) && isUnivalTree(root.right);
    }
}
__________________________________________________________________________________________________
