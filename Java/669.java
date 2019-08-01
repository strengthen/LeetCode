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
    public TreeNode trimBST(TreeNode root, int L, int R) {
        return trimBSTRec(root, L, R);
    }
    
    public TreeNode trimBSTRec(TreeNode root, int L, int R) {
        if (root == null) {
            return null;
        }
        
        if (root.val < L) {
            return trimBSTRec(root.right, L, R);
        } else if (root.val > R) {
            return trimBSTRec(root.left, L, R);
        } else {
            root.left = trimBSTRec(root.left, L, R);
            root.right = trimBSTRec(root.right, L, R);
            return root;
        }
    }
}
__________________________________________________________________________________________________
sample 37568 kb submission
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
    public TreeNode trimBST(TreeNode root, int L, int R) {
        if (root == null) {
            return null;
        } else {
            if (root.val < L) {
                return trimBST(root.right, L, R);
            } else if (root.val > R) {
                return trimBST(root.left, L, R);
            } else {
                // root.val lies in [L, R]
                root.left = trimBST(root.left, L, R);
                root.right = trimBST(root.right, L, R);
                return root;
            }
        }
    }
}
__________________________________________________________________________________________________
