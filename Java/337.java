__________________________________________________________________________________________________
sample 35692 kb submission
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
    Map<TreeNode,Integer> map = new HashMap<>();
    public int rob(TreeNode root) {
        if(map.containsKey(root))
            return map.get(root);
        if(root==null)
            return 0;
        if(root.left==null&&root.right==null)
            return root.val;
        int sum1 = rob(root.left)+rob(root.right);
        int sum2=root.val;
        if(root.left!=null&&root.left.left!=null)
            sum2+= rob(root.left.left);
        if(root.left!=null&&root.left.right!=null)
            sum2+= rob(root.left.right);
        if(root.right!=null&&root.right.left!=null)
            sum2+= rob(root.right.left);
        if(root.right!=null&&root.right.right!=null)
            sum2+= rob(root.right.right);
        int ans = Math.max(sum1,sum2);
        map.put(root,ans);
        return ans;
    }
}
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
    public int rob(TreeNode root) {
        int[] a = maxVal(root);
        return Math.max(a[0],a[1]);
    }
    
    private int[] maxVal(TreeNode node) {
        if (node == null) {
            return new int[2];
        }
        int[] left = maxVal(node.left);
        int[] right = maxVal(node.right);
        return new int[]{Math.max(left[1] + right[1] + node.val, left[0] + right[0]), left[0] + right[0]};
        
    }
}
__________________________________________________________________________________________________
