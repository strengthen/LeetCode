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
        private int ans ;
    public int minCameraCover(TreeNode root) {
           ans=0;
        if (dfs(root) == 0) ans++;
        return ans;
        
    }
     public int dfs(TreeNode root) {
        if (root == null) return 1;
        int l = dfs(root.left);
        int r = dfs(root.right);
        if (l == 0 || r == 0) {
            ans++;
            return 2;
        }
        if(l==2||r==2)
        {
            return 1;
        }
        return 0;
    }
}
__________________________________________________________________________________________________
sample 37116 kb submission
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
    
    int camera = 0;
    Set<TreeNode> monitored = new HashSet<>();
    Map<TreeNode, TreeNode> parents = new HashMap<>();
    Map<TreeNode, Integer> levels = new HashMap<>();
    PriorityQueue<TreeNode> q = new PriorityQueue<>(
        10, (a,b) -> levels.get(b) - levels.get(a));
    
    public int minCameraCover(TreeNode root) {
        traverse(root, 0);
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            if (monitored.contains(node)) {
                continue;
            }
            
            camera++;
            TreeNode p = parents.get(node);
            if (p == null) {
                monitor(node); 
                continue;
            }
            monitor(p);
            TreeNode pp = parents.get(p);
            if (pp != null) {
                TreeNode ppp = parents.get(pp);
                if (ppp != null && !monitored.contains(ppp)) {
                    q.add(ppp);
                }
            }

        }
        
        return camera;
    }
    
    void monitor(TreeNode node) {
        monitored.add(node);
        monitored.add(node.left);
        monitored.add(node.right);
        monitored.add(parents.get(node));
    }
    
    void traverse(TreeNode root, int level) {
        levels.put(root, level);        
        if (root.left == null && root.right == null) { // leaf
            q.add(root);
            return;
        }
        if (root.left != null) {
            parents.put(root.left, root);
            traverse(root.left, level+1);
        }
        if (root.right != null) {
            parents.put(root.right, root);
            traverse(root.right, level+1);
        }
    }
}
__________________________________________________________________________________________________
