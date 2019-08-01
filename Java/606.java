__________________________________________________________________________________________________
sample 1 ms submission
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
    public String tree2str(TreeNode t) {
        if (t == null) return "";
        
        StringBuilder sb = new StringBuilder();
        preOrder(t,sb);
        return sb.toString();
    }
    
    public void preOrder(TreeNode root, StringBuilder sb) {
        //Empty tree return
        if (root == null) return;
        
        sb.append(root.val);
        
        //left subtree
        if(root.left !=null){
          sb.append("(");
          preOrder(root.left, sb);
          sb.append(")");  
        }
        
        if(root.right!=null) {
            if(root.left == null) {
                sb.append("()");
            }
            sb.append("(");
            preOrder(root.right, sb);
            sb.append(")");   
          } 
      }
    }
__________________________________________________________________________________________________
sample 37980 kb submission
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
    public String tree2str(TreeNode root) {
        if (root == null) return "";
        StringBuilder sb = new StringBuilder();
        helper(root, sb);
        return sb.toString();
    }
    
    private void helper(TreeNode root, StringBuilder sb) {
        if (root == null) return;
        sb.append(root.val);
        if (root.left == null && root.right == null) return;
        sb.append('(');
        helper(root.left, sb);
        sb.append(')');
        if (root.right == null) return;
        sb.append('(');
        helper(root.right, sb);
        sb.append(')');
    }
}
__________________________________________________________________________________________________
