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
    public int maxAncestorDiff(TreeNode root) {
        if (root == null){
            return 0;
        }
        
        return maxDiff(root, root.val, root.val);
    }
    
    private int maxDiff(TreeNode node, int minSoFar, int maxSoFar){
        if (node == null){
            return Math.abs(maxSoFar - minSoFar);
        }
        
        if (node.val < minSoFar){
            minSoFar = node.val;
        }
        
        if (node.val > maxSoFar){
            maxSoFar = node.val;
        }
        
        return Math.max(maxDiff(node.left, minSoFar, maxSoFar), maxDiff(node.right, minSoFar, maxSoFar));
    }
}
__________________________________________________________________________________________________
sample 37140 kb submission
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
    private int maxDiff = 0;
    public int maxAncestorDiff(TreeNode root) {
        if (null == root) {
            return maxDiff;
        }
        traverseTree(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
        return maxDiff;
    }
    // 如果是分治法，则每层递归的计算结果都需要return，在本题中需要定义1个class封装子树min,子树max,子树maxDiff
    private void traverseTree(TreeNode root, int maxValue, int minValue) {
        if (null == root) {
            return;
        }
        // 面对真正的根节点，初始化maxValue和minValue为自身，因为Null->树根节点过程中的maxDiff=0
        if (Integer.MIN_VALUE == maxValue) {
            maxValue = root.val;
        }
        if (Integer.MAX_VALUE == minValue) {
            minValue = root.val;
        }
        int maxDiffInCurLevel = Math.max(Math.abs(maxValue - root.val), Math.abs(minValue - root.val));
        maxDiff = Math.max(maxDiff, maxDiffInCurLevel);
        
        maxValue = Math.max(maxValue, root.val);
        minValue = Math.min(minValue, root.val);
        traverseTree(root.left, maxValue, minValue);
        traverseTree(root.right, maxValue, minValue);
    }
}
__________________________________________________________________________________________________
