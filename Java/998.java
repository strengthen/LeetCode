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
    public TreeNode insertIntoMaxTree(TreeNode root, int val) {
        return helper(root, val);
    }
    private TreeNode helper(TreeNode root, int val){
        TreeNode current = new TreeNode(val);
        if(root == null) return current;
        if(root.val < val){
            current.left = root;
            return current;
        }
        else{
            root.right = helper(root.right, val);
            return root;
        }
    }
}
__________________________________________________________________________________________________
sample 36548 kb submission
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
    public TreeNode insertIntoMaxTree(TreeNode root, int val) {
        if (root == null)
            return new TreeNode(val);
        if (val > root.val) {
            TreeNode newNode = new TreeNode(val);
            newNode.left = root;
            return newNode;
        } else {
            root.right = insertIntoMaxTree(root.right, val);
            // root.left = insertIntoMaxTree(root.left, val);
        }
        return root;
    }
}
__________________________________________________________________________________________________
