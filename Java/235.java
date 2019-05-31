__________________________________________________________________________________________________
sample 4 ms submission
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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root.val > Math.max(p.val, q.val)) {
            return lowestCommonAncestor(root.left, p, q);
        } else if (root.val < Math.min(p.val, q.val)) {
            return lowestCommonAncestor(root.right, p, q);
        } else {
            return root;
        }
    }
}
__________________________________________________________________________________________________
sample 32644 kb submission
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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(p.val < q.val) {
            return findLCA(root, p, q);
        }
        else {
            return findLCA(root, q, p);
        }
    }
    
    public TreeNode findLCA(TreeNode root, TreeNode p, TreeNode q) {
        if(root.val > p.val && root.val < q.val)    return root;
        if(root == p || root == q)  return root;
        if(root.val > q.val)    return findLCA(root.left, p, q);
        else    return findLCA(root.right, p, q);
    }
}
__________________________________________________________________________________________________
