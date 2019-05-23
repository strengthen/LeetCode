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
    int max = Integer.MIN_VALUE;
    
    public int maxPathSum(TreeNode root) {
        helper(root);
        return max;
    }
    
    public int helper(TreeNode root) {
        if (root==null) return 0;
        int l = Math.max(0, helper(root.left));
        int r = Math.max(0, helper(root.right));
        max = Math.max(max, l+r+root.val);
        return Math.max(l, r) + root.val;
    }
}
__________________________________________________________________________________________________
sample 37232 kb submission
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
    public int maxPathSum(TreeNode root) {
        if (root==null)
            return 0;

        return maxPathSumCore(root)[0];
    }

    /**
     *
     * Return : int[], [0]-maxPathValue, [1]-maxStrightPathValue
     * */
    public int[] maxPathSumCore(TreeNode root){
        int[] curRes = new int[2];
        if (root == null) { //递归出口
            Arrays.fill(curRes, Integer.MIN_VALUE);
            return curRes;
        }

        int[] leftRes = maxPathSumCore(root.left);
        int[] rightRes = maxPathSumCore(root.right);
        int[] sonsMaxRes = new int[2];
        sonsMaxRes[0] = Integer.max(leftRes[0], rightRes[0]);
        sonsMaxRes[1] = Integer.max(leftRes[1], rightRes[1]);
        
        curRes[0] = Integer.max(sonsMaxRes[0], root.val + (leftRes[1]>0?leftRes[1]:0) + (rightRes[1]>0?rightRes[1]:0) );
        curRes[1] = root.val + (sonsMaxRes[1]>0?sonsMaxRes[1]:0); //***bug:三目表达式最外层一定要套括号！！
        return curRes;
    }
}
__________________________________________________________________________________________________
