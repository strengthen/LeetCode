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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ans = new ArrayList<>();
        dfs(root, new String(), ans);
        return ans;
    }
    
    private void dfs(TreeNode root, String s, List<String> ans) {
        if (root == null) {
            return;
        }
        if (root.left == null && root.right == null) {
            ans.add(s + root.val);
            return;
        }
        dfs(root.left, s + root.val + "->", ans);
        dfs(root.right, s + root.val + "->", ans);
    }
}
__________________________________________________________________________________________________
sample 35900 kb submission
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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> list = new ArrayList<>();
        if (root == null) {
            return list;
        }
        String s = "";
        helper(root, list, s);
        return list;
    }
    
    public void helper(TreeNode root, List<String> list, String s) {   
        s += root.val;
        if (root.left == null && root.right == null) {
            list.add(s);
            return;
        }
        if (root.left != null) {
            helper(root.left, list, s = s + "->");
            s = s.substring(0, s.length() - 2);
        }
        if (root.right != null) {
            helper(root.right, list, s = s + "->");
            s = s.substring(0, s.length() - 2);
        }       
    }
}
__________________________________________________________________________________________________
