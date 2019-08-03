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
    int rinorder( TreeNode root , int sumSoFar ){
        if( root == null) {
            return sumSoFar;
        }
        
        //update for right subtree
        sumSoFar = rinorder( root.right, sumSoFar);
        
        //update for this node
        sumSoFar += root.val;
        
        //store
        root.val = sumSoFar ;
        
        //update for left subtree
        sumSoFar = rinorder( root.left, sumSoFar);
        
        //return
        return sumSoFar;
    }
    
    public TreeNode bstToGst(TreeNode root) {
        rinorder(root , 0 );
        return root;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
