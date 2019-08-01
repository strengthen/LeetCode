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
//     public TreeNode constructMaximumBinaryTree(int[] nums) {
        
//     }
    TreeNode root = null;
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        helper(nums, 0);
        return root;
    }
    
    private void helper(int[] nums, int i) {
        if (i == nums.length) {
            return;
        }
        TreeNode n = new TreeNode(nums[i]);
        if (root == null) {
            root = n;
        } else if (root.val < n.val) {
            n.left = root;
            root = n;
        } else {
            TreeNode pre = root, cur = root.right;
            while (cur != null && cur.val > n.val) {
                pre = cur;
                cur = cur.right;
            }
            n.left = cur;
            pre.right = n;
        }
        helper(nums, i + 1);
    }
}
__________________________________________________________________________________________________
sample 37960 kb submission
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
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return helper(nums, 0, nums.length - 1);
    }
    
    private TreeNode helper(int[] nums, int start, int end) {
        if (start > end) return null;
        
        int max = nums[start];
        int index = start;
        for (int i = start; i <= end; i++) {
            if (nums[i] > max) {
                max = nums[i];
                index = i;
            }
        }
        
        TreeNode node = new TreeNode(max);
        node.left = helper(nums, start, index - 1);
        node.right = helper(nums, index + 1, end);
        
        return node;
    }
}
__________________________________________________________________________________________________
