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
 private String ans = "~"; // dummy value '~' > 'z'
    public String smallestFromLeaf(TreeNode root) {
        return dfs(root, "");
    }
    private String dfs(TreeNode n, String str) {
        if (n == null) return ans;
        str = (char)('a'+n.val) + str;
        if (n.left == null && n.right == null && str.compareTo(ans) < 0){
            ans = str;
        }
        dfs(n.left, str);
        dfs(n.right, str);
        return ans;
    }
}
__________________________________________________________________________________________________
sample 37044 kb submission
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
    public String smallestFromLeaf(TreeNode root) {
        // dfs
        return dfs(root, "");
    }
    private String dfs(TreeNode root, String suffix) {
        if (root == null) {
            return suffix;
        }
        suffix = "" + (char)('a' + root.val) + suffix;
        if (root.left == null && root.right == null) {
            return suffix;
        }
        if (root.left == null) {
            return dfs(root.right, suffix);
        }
        if (root.right == null) {
            return dfs(root.left, suffix);
        }
        String left = dfs(root.left, suffix);
        String right = dfs(root.right, suffix);
    
        if(left.compareTo(right) <= 0) {
            return left;
        }
        return right;
    }
}
__________________________________________________________________________________________________
