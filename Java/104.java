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
    public int maxDepth(TreeNode root) {
        if(root==null){
            return 0;
        }        
        return Math.max(maxDepth(root.right),maxDepth(root.left))+1;        
    }
}
__________________________________________________________________________________________________
sample 34456 kb submission
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
    public int maxDepth(TreeNode root) {
        if(root ==null) return 0;
        int maxDepth = Integer.MIN_VALUE;
        return Math.max(maxDepth(root.left) + 1, maxDepth(root.right)+1);
    }
}
__________________________________________________________________________________________________
