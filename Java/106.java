__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int n = postorder.length;
        if (n == 0) return null;
        return helper(inorder, postorder, n - 1, 0, n - 1);
    }
    private TreeNode helper(int[] inorder, int[] postorder, int s1, int e1,int s2) {
        if (s1 < e1 || s2 < 0) return null;
        TreeNode root = new TreeNode (postorder[s2]);
        
        int index = s1;
        for (int i = s1; i >= e1; i--) {
            if (inorder[i] == postorder[s2]) {
                index = i;
                break;
            }
        }
        
        root.left = helper(inorder, postorder, index - 1, e1, s2 - s1 + index - 1);
        root.right = helper(inorder, postorder, s1, index + 1,s2 - 1);
        return root;
    }
}
__________________________________________________________________________________________________
sample 34408 kb submission
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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        index = inorder.length - 1;
        Map<Integer, Integer> position = new HashMap<>();

        for (int i = 0; i < inorder.length; i++) {
            position.put(inorder[i], i);
        }

        return buildTree(postorder, 0, postorder.length - 1, position);
    }

    private int index = 0;

    private TreeNode buildTree(int[] postorder, int start, int end, Map<Integer, Integer> position) {
        if (start > end || index < 0) {
            return null;
        }
        TreeNode root = new TreeNode(postorder[index--]);
        if (start == end) return root;
        int mid = position.get(root.val);
        root.right = buildTree(postorder, mid + 1, end, position);
        root.left = buildTree(postorder, start, mid - 1, position);
        return root;
    }
}
__________________________________________________________________________________________________
