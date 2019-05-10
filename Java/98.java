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
    public boolean isValidBST(TreeNode root) {
        if(root == null){
            return true;
        }
        return helper(root,Long.MIN_VALUE,Long.MAX_VALUE);
    }
    
    public boolean helper(TreeNode root, long leftBound, long rightBound){
        if(root ==  null){
            return true;
        }
        if(root.val <= leftBound || root.val >= rightBound){
            return false;
        }
        return helper(root.left,leftBound,root.val) && helper(root.right,root.val,rightBound);
    }
}
__________________________________________________________________________________________________
sample 34512 kb submission
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
    public boolean isValidBST(TreeNode root) {
        int[] result= validateNode(root , null);
        return result[0] == 1;
    }
    
    private int[] validateNode(TreeNode node, TreeNode parent) {
        if(node !=null){
            int[] l =  validateNode(node.left, node);
            int[] r = validateNode(node.right, node);
            if(l[0]==1 && r[0]==1) {
                if((node.left ==null || l[2]<node.val) && (node.right==null|| r[1]>node.val)) {
                    return new int[]{1, l[1], r[2]};
                }else {
                    return new int[]{0,0,0};
                }
            }else {
                return new int[]{0,0,0};
            }
        }else if(parent!= null) {
            return new int[]{1, parent.val, parent.val};
        }
        return new int[]{1,0,0};   
    }
}
__________________________________________________________________________________________________
