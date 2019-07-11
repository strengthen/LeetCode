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
    int rs = 0;
    public int sumOfLeftLeaves(TreeNode root) {
        if(root == null) return 0;
        sumLeftLeaves2(root);
        return rs;
    }
    
     public void sumLeftLeaves2(TreeNode node){
        if(node == null) return;
        if(node.left != null ){
            if (node.left.left == null){
                if (node.left.right == null){
                    rs +=node.left.val;
                }
            }
            sumLeftLeaves2(node.left);
        }
        if(node.right != null){
            sumLeftLeaves2(node.right);
        }
    }
}
__________________________________________________________________________________________________
sample 36704 kb submission
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
    private class ReturnType {
        boolean isNode;
        int val;
        public ReturnType(boolean isNode, int val) {
            this.isNode  = isNode;
            this.val = val;
        }
        
    }
    
    public int sumOfLeftLeaves(TreeNode root) {
              return  sumOfLeftLeaves(root, false).val;
    }
    
    private ReturnType sumOfLeftLeaves(TreeNode node, boolean isLeft) {
        if (node == null) {
            return new ReturnType(false,0);
        }
        
       ReturnType leftSum = sumOfLeftLeaves(node.left, true);
       ReturnType rightSum = sumOfLeftLeaves(node.right, false); 
        
       if (isLeft && !leftSum.isNode  && !rightSum.isNode ) {
           return new ReturnType(true, node.val);
       }
        
       return  new ReturnType(true, leftSum.val + rightSum.val);        
    }   
}
__________________________________________________________________________________________________
