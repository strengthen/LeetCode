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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> al = new ArrayList<Integer>();
        computePostOrder(root, al);
        return al;
    }
    
    private void computePostOrder(TreeNode root, List<Integer> al) {
        if(root == null) return;
        computePostOrder(root.left, al);
        computePostOrder(root.right, al);
        al.add(root.val);
        return;
    }
}
__________________________________________________________________________________________________
sample 33408 kb submission
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        helper(root, res);
        return res;
    }
    
    public void helper(TreeNode root, List<Integer> res){
        if(root == null) return;
        if(root.left!=null) helper(root.left, res);
        
        if(root.right!=null) helper(root.right, res);
        res.add(root.val);
    }
}
__________________________________________________________________________________________________
