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
    
    private List<Integer> preorder;
    
    public Solution() {
        preorder = new ArrayList<>();
    }
    
    public List<Integer> preorderTraversal(TreeNode root) {
        if (root != null) {
            preorder.add(root.val);
            preorder = preorderTraversal(root.left);
            preorder = preorderTraversal(root.right);
            return this.preorder;
        }
        else
            return this.preorder;
    }
}
__________________________________________________________________________________________________
sample 33388 kb submission
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
    
   private List<Integer> list = new ArrayList(); 
    
    public List<Integer> preorderTraversal(TreeNode root) {
        preOrderHelper(root);
        return list;
    }
    
    private void preOrderHelper(TreeNode root){
        if(root == null) {
            return;
        }
        list.add(root.val);
        preOrderHelper(root.left);
        preOrderHelper(root.right);
    }
}
__________________________________________________________________________________________________
