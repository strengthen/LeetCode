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
    public TreeNode sortedArrayToBST(int[] nums) {
                if (nums==null || nums.length==0)
            return null;
        return helper(nums,0,nums.length-1);
    }

    public TreeNode helper(int[] nums,int low,int high){
        if (low>high)
            return null;
        if (low == high)
            return new TreeNode(nums[low]);
        int mid = (low+high)/2;
        TreeNode res = new TreeNode(nums[mid]);
        res.left = helper(nums,low,mid-1);
        res.right = helper(nums,mid+1,high);
        return res;
    }
}
__________________________________________________________________________________________________
sample 34432 kb submission
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
    public TreeNode sortedArrayToBST(int[] nums) {
        return createTree(nums, 0,nums.length-1);
    }
    
    public TreeNode createTree(int[] nums, int start, int end){
        
        if(start > end)
            return null;        
        int mid = (start + end)/2;        
        TreeNode root = new TreeNode(nums[mid]);        
        root.left = createTree(nums, start, mid -1);
        root.right = createTree(nums, mid+1,end);        
        return root;        
    }
}
__________________________________________________________________________________________________
