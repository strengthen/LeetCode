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
    public int widthOfBinaryTree(TreeNode root) {
        List<Integer> startIdx=new ArrayList<>();
        return widthOfBinaryTreeDFS(root, startIdx, 0, 0);
    }
    
    public int widthOfBinaryTreeDFS(TreeNode node, List<Integer> startIdx, int level, int idx){
        if(node==null){
            return 0;
        } else{
            if(level>=startIdx.size()){
                startIdx.add(idx);
            }
            return Math.max(idx-startIdx.get(level)+1, 
                            Math.max(widthOfBinaryTreeDFS(node.left, startIdx, level+1, idx*2+1),
                                     widthOfBinaryTreeDFS(node.right, startIdx, level+1, idx*2+2)));
        }
    }
}
__________________________________________________________________________________________________
sample 36972 kb submission
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
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null)
            return 0;
        
        ArrayDeque<TreeNode> nodes = new ArrayDeque();
        ArrayDeque<Integer> indices = new ArrayDeque();
        nodes.add(root);
        indices.add(1);
        int maxWidth = 0;
        
        while (!nodes.isEmpty()) {
            int left = 0, right = 0;
            int size = nodes.size();
            for (int i=0; i < size; i++) {
                TreeNode node = nodes.poll();
                int index = indices.poll();
                if (i == 0)
                    left = index;
                if (i == size-1)
                    right = index;
                
                if (node.left != null) {
                    nodes.add(node.left);
                    indices.add(2*index);
                }
                if (node.right != null) {
                    nodes.add(node.right);
                    indices.add(2*index+1);
                }
                maxWidth = Math.max(maxWidth, right-left+1);
            }
        }
        
        return maxWidth;
    }
}
__________________________________________________________________________________________________
