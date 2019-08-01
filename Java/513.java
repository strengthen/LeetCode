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
    int max = 0;
    int value = 0;
    
    public int findBottomLeftValue(TreeNode root) {
        preorder(root, 1);
        return value;
    }
    
    void preorder(TreeNode root, int depth) {
        if (root == null) {
            return;
        }
        
        if (depth > max) {
            max = depth;
            value = root.val;
        }
        
        preorder(root.left, depth + 1);
        preorder(root.right, depth + 1);
    }
}
__________________________________________________________________________________________________
sample 37632 kb submission
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
    TreeMap<Integer, TreeNode> map = new TreeMap<>();
    
    public void dfs(TreeNode cur, int depth) {
            if (cur == null) return;
            if (!map.containsKey(depth)) map.put(depth, cur);
            dfs(cur.left, depth+1);
            dfs(cur.right, depth+1);
        }

        public int findBottomLeftValue(TreeNode root) {
            dfs(root, 0);
            return map.get(map.lastKey()).val;
        }
}
__________________________________________________________________________________________________
