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
    
    public int minDiffInBST(TreeNode root) {
        inOrder(root);
        return min;
    }
    
     int min = Integer.MAX_VALUE;
     Integer prev = null;
    
    public void inOrder(TreeNode node){
        
        if(node==null)
            return;
        
        inOrder(node.left);
        
        if(prev!=null){
            min = Math.min(min,Math.abs(node.val-prev));
        }
        prev = node.val;
        inOrder(node.right);
    }
    
}
__________________________________________________________________________________________________
sample 35748 kb submission
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
    int min=0;
    int last=0;
    boolean first=false;
    public int minDiffInBST(TreeNode root) {
        min=Integer.MAX_VALUE;
        first=false;
        help(root);
        return min;
    }
    void help(TreeNode n){
        if (n==null) return;
        help(n.left);
        if (n.left==null  && !first){
            first=true;
        }else{
            min=Math.min(n.val-last, min);    
        }
        last=n.val;
        help(n.right);
    }
}
__________________________________________________________________________________________________
