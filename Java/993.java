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
    public boolean isCousins(TreeNode root, int x, int y) {
        if (root.val == x || root.val == y) {
            return false;
        }
        int[] parentX = new int[1];
        int[] parentY = new int[1];
        int xLevel = findLevelParent(root, x, parentX);
        int yLevel = findLevelParent(root, y, parentY);
        if (xLevel != yLevel || parentX[0] == parentY[0]) {
            return false;
        }
        return true;
    }
    
    private int findLevelParent(TreeNode root, int target, int[] parent) {
        if (root == null) {
            return -1;
        }
        if (root.val == target) {
            return 0;
        }
        int left = findLevelParent(root.left, target, parent);
        if (left != -1) {
            if (left == 0) {
                parent[0] = root.val;
            }
            return left + 1;
        }
        int right = findLevelParent(root.right, target, parent);
        if (right != -1) {
            if (right == 0) {
                parent[0] = root.val;
            }
            return right + 1;
        }
        return -1;
    }
}
__________________________________________________________________________________________________
sample 36560 kb submission
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
    Map<Integer, Integer> depth;
    Map<Integer, TreeNode> parent;

    public boolean isCousins(TreeNode root, int x, int y) {
        depth = new HashMap();
        parent = new HashMap();
        dfs(root, null);
        return (depth.get(x) == depth.get(y) && parent.get(x) != parent.get(y));
    }

    public void dfs(TreeNode node, TreeNode par) {
        if (node != null) {
            depth.put(node.val, par != null ? 1 + depth.get(par.val) : 0);
            parent.put(node.val, par);
            dfs(node.left, node);
            dfs(node.right, node);
        }
    }
}
__________________________________________________________________________________________________
