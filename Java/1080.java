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
    class Pair {
        TreeNode node;
        int max_val;
        
        Pair(TreeNode n, int v) {
            node = n;
            max_val = v;
        }
    }
    
    public TreeNode sufficientSubset(TreeNode root, int limit) {
        Pair res = helper(root, 0, limit);
        
        return res.node;
    }
    
    Pair helper(TreeNode root, int cur, int limit) {
        Pair left = null;
        Pair right = null;
        
        if (root.left == null && root.right == null) {
            if (cur + root.val < limit) {
                return new Pair(null, root.val);
            } else {
                return new Pair(root, root.val);
            }
        }
        
        int max_val = Integer.MIN_VALUE;
        if (root.left != null) {
            left = helper(root.left, cur+root.val, limit);
            max_val = Math.max(left.max_val, max_val);
        }
        
        if (root.right != null) {
            right = helper(root.right, cur+root.val, limit);
            max_val = Math.max(right.max_val, max_val);
        }
        
        if (left != null && left.node == null) {
            root.left = null;
        }
        if (right != null && right.node == null) {
            root.right = null;
        }
        
        // if (root.val == 11) {
        //     System.out.println("mv=" + max_val + ", left:" 
        //                        + left.node + ", " +left.max_val
        //                        + ", right:" + right.node + ", " + right.max_val);
        // }
        
        if (max_val + root.val + cur < limit) {
            return new Pair(null, max_val + root.val);
        } else {
            return new Pair(root, max_val + root.val);
        }
    }
}
__________________________________________________________________________________________________
sample 2 ms submission
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
    public TreeNode sufficientSubset(TreeNode root, int limit) {
        TreeNode dummy = new TreeNode(0);
        dummy.left = root;
        check(dummy, 0, limit);
        return dummy.left;
    }

    private void check(TreeNode node, int sumFromRoot, int limit){
    	if (node.left != null){
    		if (sumFromRoot + node.val + getMaxSum(node.left) < limit){
    			node.left = null;
    		} else {
    			check(node.left, sumFromRoot + node.val, limit);
    		}
    	}
    	if (node.right != null){
    		if (sumFromRoot + node.val + getMaxSum(node.right) < limit){
    			node.right = null;
    		} else {
    			check(node.right, sumFromRoot + node.val, limit);
    		}
    	}
    }

    private int getMaxSum(TreeNode node){
    	if (node.left == null && node.right == null){
    		return node.val;
    	} else if (node.left == null){
    		return node.val + getMaxSum(node.right);
    	} else if (node.right == null){
    		return node.val + getMaxSum(node.left);
    	} else {
    		return node.val + Math.max(getMaxSum(node.right), getMaxSum(node.left));
    	}
    }
}
__________________________________________________________________________________________________
sample 3 ms submission
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
    public TreeNode sufficientSubset(TreeNode root, int limit) {
        if(!isValid(root,limit)) return null;
        delete(root,limit);
        return root;
    }
    
    private void delete(TreeNode node,int limit){
        if(node==null) return;
        if(isValid(node.left,limit-node.val)) delete(node.left,limit-node.val);
        else node.left=null;
        if(isValid(node.right,limit-node.val)) delete(node.right,limit-node.val);
        else node.right=null;
    }
    private boolean isValid(TreeNode node,int limit){
        if(node==null) return false;
        if(node.left==null&&node.right==null) return node.val>=limit;
        boolean left=isValid(node.left,limit-node.val),right=isValid(node.right,limit-node.val);
        return left||right;
    }
}