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
    public boolean isSymmetric(TreeNode root) {
        return isMirror(root, root);
    }
    
    public boolean isMirror(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) return true;
        if (t1 == null || t2 == null) return false;
        return (t1.val == t2.val)
            && isMirror(t1.right, t2.left)
            && isMirror(t1.left, t2.right);
    }
}
__________________________________________________________________________________________________
sample 34928 kb submission
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
    public boolean isSymmetric(TreeNode root) {
        if (root == null) return true;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        q.add(root);
        while (!q.isEmpty()) {
            TreeNode x = q.poll();
            TreeNode y = q.poll();
            if (x == null && y == null) continue;
            if (x == null && y != null) return false;
            if (x != null && y == null) return false;
            if (x.val != y.val) return false;
            q.add(x.right);
            q.add(y.left);
            q.add(x.left);
            q.add(y.right);
        }
        return true;
        
    }
}
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
    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        TreeNode p = root.left;
        TreeNode q = root.right;
        if (!check(p, q)) {
            return false;
        }
        Queue<TreeNode> qp = new LinkedList<>();
        Queue<TreeNode> qq = new LinkedList<>();
        qp.offer(p);
        qq.offer(q);
        while (!qp.isEmpty()) {
            p = qp.poll();
            q = qq.poll();
            if (!check(p, q)) {
                return false;
            }
            if (p != null) {
                qp.offer(p.left);
                qq.offer(q.right);
                qp.offer(p.right);
                qq.offer(q.left);
            }
        }
        return true;
    }
    
    private boolean check(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        } else if (p == null || q == null) {
            return false;
        } else {
            return p.val == q.val;
        }
    }
}