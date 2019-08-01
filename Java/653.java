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
    public boolean findTarget(TreeNode root, int k) {
        return traverseNode(root, k, root);
    }
    
    private boolean traverseNode(TreeNode node, int k, TreeNode root) {
        if (node == null) {
            return false;
        }
        boolean result = node.val * 2 != k ? findTargetNode(root, k-node.val) : false;
        return result || traverseNode(node.left, k, root) || traverseNode(node.right, k, root);
    }
    
    private boolean findTargetNode(TreeNode node, int n) {
        if (node == null) {
            return false;
        }
        if (node.val == n) {
            return true;
        } else if (node.val < n) {
            return findTargetNode(node.right, n);
        } else {
            return findTargetNode(node.left, n);
        }
    }
}
__________________________________________________________________________________________________
sample 38484 kb submission
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
    public boolean findTarget(TreeNode root, int k) {
        List < Integer > list = new ArrayList();
        inorder(root, list);
        int l = 0, r = list.size() - 1;
        while (l < r) {
            int sum = list.get(l) + list.get(r);
            if (sum == k)
                return true;
            if (sum < k)
                l++;
            else
                r--;
        }
        return false;
    }
    public void inorder(TreeNode root, List < Integer > list) {
        if (root == null)
            return;
        inorder(root.left, list);
        list.add(root.val);
        inorder(root.right, list);
    }
}
__________________________________________________________________________________________________
