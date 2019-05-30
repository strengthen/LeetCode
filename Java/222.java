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
    public int countNodes(TreeNode root) {
        if (root == null)
            return 0;
        
        return countNodes(root.left) + countNodes(root.right) + 1;
    }
}
__________________________________________________________________________________________________
sample 36656 kb submission
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
    public int GetTreeHeight(TreeNode node)
    {
        if(node == null) return 0;
        int leftH = GetTreeHeight(node.left);
        return 1 + leftH;
    }
    public int CountTreeLeave(TreeNode node,int height, int curHeight)
    {
        if(node == null) return 0;
        if(node.left == null && node.right == null)
        {
            if(curHeight == height) return 1;
            else return 0;
        }
        else
        {
            return CountTreeLeave(node.left, height, curHeight+1) + CountTreeLeave(node.right, height, curHeight+1);
        }
    }

    public int countNodes(TreeNode root)
    {
        if(root == null) return  0; 
        int height = GetTreeHeight(root);
        int countLeave = CountTreeLeave(root, height,1);
        int nodeNum = (int) Math.pow(2, height-1)-1;
        return nodeNum+countLeave;
    }
}
__________________________________________________________________________________________________
