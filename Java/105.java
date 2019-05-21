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
    
    int in, pre;
    
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildTreeHelper(preorder, inorder, Long.MAX_VALUE);
    }
    
    public TreeNode buildTreeHelper(int[] preorder, int[] inorder, long val) {
        if (in >= inorder.length || val == inorder[in])
            return null;
        
        TreeNode root = new TreeNode(preorder[pre++]);
        root.left = buildTreeHelper(preorder, inorder, root.val);
        in++;
        root.right = buildTreeHelper(preorder, inorder, val);
        return root;
    }
}
__________________________________________________________________________________________________
sample 34448 kb submission
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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder.length == 0) {
            return null;
        }
        
        Deque<TreeNode> stack = new LinkedList<>();
        TreeNode root = new TreeNode(preorder[0]);
        TreeNode prev = root;
        for (int i = 1, j = 0; i < preorder.length; i++) {
            if (prev.val != inorder[j]) {
                prev.left = new TreeNode(preorder[i]);
                stack.push(prev);
                prev = prev.left;
            } else {
                j++;
                while (!stack.isEmpty() && stack.peek().val == inorder[j]) {
                    prev = stack.pop();
                    j++;
                }
                prev = prev.right = new TreeNode(preorder[i]);
            }   
        }
        return root;
    }
}
__________________________________________________________________________________________________
