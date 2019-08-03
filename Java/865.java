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
    TreeNode ans = null;
    int maxDepth=0;
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        travel(root, 0);
        return ans;
    }
    
    
    private int travel(TreeNode node, int depth){
        if (node == null){
            maxDepth = Math.max(maxDepth, depth);
            return depth;
        }
        int left = travel(node.left, depth+1);
        int right = travel(node.right, depth+1);
        
        if (left == maxDepth && right == maxDepth){
            ans = node;
        }
        return Math.max(left, right);
        
    }
}
__________________________________________________________________________________________________
sample 36740 kb submission
/*
 * Definition for a binary tree node.
 */
  public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
      
      public String toString() {
          return "("+this.val+")";
      }
  }

class Solution {
    int maxDepth = 0;
    
    Map<Integer, List<TreeNode>> map = new HashMap<>();
    TreeNode lca = null;
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        
        helper (root, 0);
        // System.out.println(map);
        //now we need to do LCA for all the nodes in the maxdeth
        if (map.get(maxDepth).size() == 1)
            return map.get(maxDepth).get(0);
        List<TreeNode> list = map.get(maxDepth);
        TreeNode prev = list.get(0);
        for (int i = 1; i < list.size(); i++) {
            TreeNode curr = list.get(i);
            TreeNode currLca = lowestCA(root, prev, curr);
            if (lca == null) {
                lca = currLca;
            } else if (lca != currLca) {
                //they have different roots now - so,
                lca = lowestCA(root, lca, currLca);
            }
            if (lca == root)
                return root;
            prev = curr;
        }
        return lca;
    }
    
    public void helper (TreeNode root, int depth) {
        if (root == null)
            return;
        if (!map.containsKey(depth))
            map.put(depth, new ArrayList<>());
        maxDepth = Math.max(depth, maxDepth);
        map.get(depth).add(root);
        helper (root.left,  depth+1);
        helper (root.right,  depth+1);
    }
    
    public TreeNode lowestCA(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || p == root || q == root) {
            return root;
        }
        TreeNode left = lowestCA(root.left, p, q);
        TreeNode right = lowestCA(root.right, p, q);
        if (left != null && right != null) {
            return root;
        } else  if (left != null || right != null ) {
            if (left == null)
                return right;
            if (right == null)
                return left;
        }
        return null;
    }
}
__________________________________________________________________________________________________
