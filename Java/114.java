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
    TreeNode prev;
    
    public void flatten(TreeNode root) {
        //base case
        if(root == null){
            return;
        }    
        
        prev = null;
        
        //run it in recursion pre-order
        flattenTree(root); 
    }
    
    //Function to flatten tree with pre-order traversal
    public void flattenTree(TreeNode current){
         if(current == null){
             return;
         }   
        
         //start addiing current to the right of the prev 
        if(prev != null){
            prev.right = current;
            prev.left = null;
        }
        prev = current;
        
        //get all nodes form left --> right and add to the prev
        TreeNode right = current.right;
        flattenTree(current.left);
        flattenTree(right);
    }
}
__________________________________________________________________________________________________
sample 34252 kb submission
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

// 04/03/2019
// Runtime: 0 ms, beat 100%

class Solution {
    public void flatten(TreeNode root) {
        if (root == null) {
            return;
        }
        flattenHelper(root, new TreeNode[] {null});
    }
    
    private void flattenHelper(TreeNode root, TreeNode[] prev) {
        if (root == null) {
            return;
        } 
        flattenHelper(root.right, prev);
        flattenHelper(root.left, prev);
        root.right = prev[0];
        root.left = null;
        prev[0] = root;
    }
}
__________________________________________________________________________________________________
