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
    TreeNode first, second;
    TreeNode pre;
    public void recoverTree(TreeNode root) {
        traverse (root);
        int tmpVal = first.val;
        first.val = second.val;
        second.val = tmpVal;
    }
    private void traverse (TreeNode root) {
        if (root == null) return;
        traverse (root.left);
        if (pre != null && pre.val > root.val) {
            if (first == null) first = pre;
            second = root;
        }
        pre = root;
        traverse (root.right);
    }
}
__________________________________________________________________________________________________
sample 40244 kb submission
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
    public void recoverTree(TreeNode root) {
        List<Integer> values = new ArrayList<>();
        List<TreeNode> nodes = new ArrayList<>();
        inorderTraversal(root, nodes, values);
        Collections.sort(values);
        for (int i = 0; i < nodes.size(); i++) {
            nodes.get(i).val = values.get(i);
        }
    }

    public  void inorderTraversal(TreeNode root, List<TreeNode> nodes, List<Integer> values) {
        if (root == null)
            return;
        inorderTraversal(root.left, nodes, values);
        nodes.add(root);
        values.add(root.val);
        inorderTraversal(root.right, nodes, values);
    }
}
__________________________________________________________________________________________________
