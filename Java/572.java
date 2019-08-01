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
    public boolean isSubtree(TreeNode s, TreeNode t) {
        return helper(s, t, true);
    }
    
    private boolean helper(TreeNode s, TreeNode t, boolean isRoot) {
        if (s == null || t == null) return s == t;
        
        if (s.val != t.val) {
            if (!isRoot) return false;
            
            return helper(s.left, t, true) || helper(s.right, t, true);
        } else {
            return helper(s.left, t.left, false) && helper(s.right, t.right, false) ||
                helper(s.left, t, true) || helper(s.right, t, true);
        }
    }
}
__________________________________________________________________________________________________
sample 39908 kb submission
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
    public boolean isSubtree(TreeNode s, TreeNode t) {
        if(s==null && t==null) return true;
        if(s==null || t==null) return false;
        StringBuilder sb1=new StringBuilder(), sb2=new StringBuilder();
        preorder(s, sb1);
        preorder(t, sb2);
        return sb1.indexOf(sb2.toString())>-1;
    }
    private void preorder(TreeNode t, StringBuilder sb){
        if(t==null){
            sb.append(" #");
            return;
        }
        sb.append(" "+t.val);
        preorder(t.left, sb);
        preorder(t.right, sb);
    }
}
__________________________________________________________________________________________________
