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
    public TreeNode searchBST(TreeNode root, int val) {
        if(root==null||root.val==val) return root;
        if(root.val<val){
            return searchBST(root.right,val);
        } else{
            return searchBST(root.left,val);
        }
    }
}
__________________________________________________________________________________________________
sample 38192 kb submission
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
    public TreeNode searchBST(TreeNode root, int val) {
        
        if(root == null || root.val == val)
            return root;
        
        if(root.val >= val)
            return searchBST(root.left, val);
        else
            return searchBST(root.right, val);
    }
}
__________________________________________________________________________________________________
