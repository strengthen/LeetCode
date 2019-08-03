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
  public boolean isCompleteTree(TreeNode root) {
    int nodeCount = count(root);
    int max = max(root, 1);
    return max == nodeCount;
  }

  private final int max(TreeNode root, int value) {
    if (root == null) {
      return 0;
    } else {
      int leftMax = max(root.left, value + value);
      int rightMax = max(root.right, value + value + 1);
      return Math.max(value,  Math.max(leftMax, rightMax));
    }
  }

  private final int count(TreeNode node) {
    return node == null ? 0 : 1 + count(node.left) + count(node.right);
  }
}
__________________________________________________________________________________________________
sample 36644 kb submission
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
    int maxIndex = 0;
    int count = 0;
    public boolean isCompleteTree(TreeNode root) {
        Queue<TreeNode> q= new LinkedList<>();
        if(root!=null)
            q.offer(root);
        
        boolean flag=false;
        
        while(!q.isEmpty()){
            TreeNode n=q.poll();
            
            if(n==null){
               flag=true;
            }
            else{
                if(flag) return false;
                
                q.offer(n.left);
                q.offer(n.right);
            }
            
        }   
        
        return true;
        
    }
}
__________________________________________________________________________________________________
