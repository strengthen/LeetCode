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
public class Solution {
    public int kthSmallest(TreeNode root, int k) {
        if (root == null) {
        	return -1;
        }
        
        int leftSize = TreeSize(root.left);
        
        if (leftSize == k - 1) {
        	return root.val;
        } else if (leftSize > k - 1) {
        	return kthSmallest(root.left, k);
        } else {
        	return kthSmallest(root.right, k - leftSize - 1);
        }
    }
	
	private int TreeSize(TreeNode root) {
		if (root == null) {
			return 0;
		}
		
		return TreeSize(root.left) + TreeSize(root.right) + 1;
    }
}
__________________________________________________________________________________________________
sample 35252 kb submission
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
    private static int number = 0;
    private static int count = 0;

    public int kthSmallest(TreeNode root, int k) {
        count = k;
        helper(root);
        return number;
    }
    
    public void helper(TreeNode n) {
        if( n == null ) return;
        helper(n.left);
        count--;
        if (count == 0) {
            number = n.val;
            return;
        }
         helper(n.right);
    }
}
__________________________________________________________________________________________________
