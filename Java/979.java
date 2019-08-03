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
    public int distributeCoins(TreeNode root) {
       int res = 0;
        if(root.left!=null){
            res += distributeCoins(root.left)+Math.abs(root.left.val-1);
            root.val += root.left.val-1;
           
        }
        if(root.right!=null){
            res += distributeCoins(root.right)+Math.abs(root.right.val-1);
            root.val += root.right.val-1;
        }
        return res;        
    }
}
__________________________________________________________________________________________________
sample 37012 kb submission
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
    int ans = 0;
    public int distributeCoins(TreeNode root) {
        dfs(root);
        return ans;
    }
    
    int dfs(TreeNode node) {
        if (node == null) return 0;
        int L = dfs(node.left);
        int R = dfs(node.right);
        ans += Math.abs(L) + Math.abs(R);
        return node.val + L + R - 1;
    }
}
__________________________________________________________________________________________________
