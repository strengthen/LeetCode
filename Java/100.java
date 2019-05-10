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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null){
            return true;
        } else if(p == null || q == null){
            return false;
        } else if (p.val != q.val){
            return false;
        }
        return isSameTree(p.left, q.left) & isSameTree(p.right, q.right);
    }
}
__________________________________________________________________________________________________
sample 34208 kb submission
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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        //Recursive
        /*if(p == null && q == null) return true;
        if(p == null || q == null) return false;
        if(p.val != q.val) return false;
        
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);*/
        //Iterative using BFS
        if(p == null && q == null) return true;
       // if(p == null || q == null) return false;
        Queue<TreeNode> q1 = new LinkedList<>();
        Queue<TreeNode> q2 = new LinkedList<>();
        q1.add(p);
        q2.add(q);
        while(!q1.isEmpty() && !q2.isEmpty()) {
            TreeNode n1 = q1.poll();
            TreeNode n2 = q2.poll();
            if(n1 == null && n2 == null)
                continue;
            else if(n1 == null || n2 == null) 
                return false;
            else if(n1.val != n2.val)
                return false;
            q1.add(n1.left);
            q2.add(n2.left); 
            q1.add(n1.right);
            q2.add(n2.right);
        }
        if(q1.isEmpty() && q2.isEmpty())
            return true;
        else
            return false;
    }
}
__________________________________________________________________________________________________
