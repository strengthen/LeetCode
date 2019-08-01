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
    public int findSecondMinimumValue(TreeNode root) {
        if (root == null || root.left == null && root.right == null)   return -1;
        if (root.left.val < root.right.val) {
            int findLeft = findSecondMinimumValue(root.left);
            return findLeft < 0 ? root.right.val : Math.min(findLeft, root.right.val);
        } else if (root.left.val > root.right.val) {
            int findRight = findSecondMinimumValue(root.right);
            return findRight < 0 ? root.left.val : Math.min(root.left.val, findRight);
        } 
        int findLeft = findSecondMinimumValue(root.left);
        int findRight = findSecondMinimumValue(root.right);
        if (findLeft < 0 && findRight < 0)  return -1;
        if (findLeft < 0)   return findRight;
        if (findRight < 0)  return findLeft;
        return Math.min(findLeft, findRight);
    }
}
__________________________________________________________________________________________________
sample 35236 kb submission
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
   int min = Integer.MAX_VALUE;
	int secondmin = Integer.MAX_VALUE;
    boolean wasAssigned = false;
    
    public int findSecondMinimumValue(TreeNode root) {
        findSecondMinimumR(root);
		
		if(!wasAssigned)
		{
			return -1;
		}else {
			return secondmin;
		}
    }
    
    public void findSecondMinimumR(TreeNode root)
	{
		if(root == null)
		{
			return;
		}
		
		if(root.val < min)
		{
			min = root.val;
		}
		if(root.val > min && root.val <= secondmin)
		{
			secondmin = root.val;
            wasAssigned = true;
		}
		findSecondMinimumR(root.left);
		findSecondMinimumR(root.right);
	}
}
__________________________________________________________________________________________________
