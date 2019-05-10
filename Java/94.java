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
    public List<Integer> inorderTraversal(TreeNode root) {
        final List<Integer> ret = new ArrayList<>();
        inorderTraversal(root, ret);
        return ret;
    }
    
    private void inorderTraversal(TreeNode root, List<Integer> ret) {
        if (root == null) return;
        inorderTraversal(root.left, ret);
        ret.add(root.val);
        inorderTraversal(root.right, ret);
    }
}
__________________________________________________________________________________________________
sample 33424 kb submission
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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur = root;
        while(cur!=null || !stack.isEmpty()){
            while(cur!=null){
                stack.push(cur);
                cur = cur.left;
            }
            cur =stack.pop();
            res.add(cur.val);
            cur = cur.right;
        }
        return res;
    }
}
__________________________________________________________________________________________________
