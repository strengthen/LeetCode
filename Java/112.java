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
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root==null)return false;
        
        int s = sum-root.val;
        
        boolean ans = false;
        
        if(root.left==null && root.right==null && s==0)return true;
        
        ans = ans || hasPathSum(root.left,s);
        
        ans = ans || hasPathSum(root.right,s);

        return ans;
        
    }
}
__________________________________________________________________________________________________
sample 35144 kb submission
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
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) return false;
        Stack<TreeNode> treeStack = new Stack<>();
        Stack<Integer> sumStack = new Stack<>();
        
        treeStack.push(root);
        sumStack.push(sum-root.val);
        while (!treeStack.isEmpty()) {
            TreeNode n = treeStack.pop();
            Integer curr = sumStack.pop();
            if (n.left == null && n.right == null && curr == 0) {
                return true;
            }
            if (n.right != null) {
                treeStack.push(n.right);
                sumStack.push(curr-n.right.val);
            }
            if (n.left != null) {
                treeStack.push(n.left);
                sumStack.push(curr-n.left.val);
            }
        }
        return false;
    }
}
__________________________________________________________________________________________________
