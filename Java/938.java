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
    public int rangeSumBST(TreeNode root, int L, int R) {
        int sum=0;
        
        if(root==null){
            return 0;
        }
        
        else{
           // int sum=0;
            if(L<=root.val && R>=root.val){
                sum+=root.val;
            }
            if(L<root.val){
                sum+=rangeSumBST(root.left,L,R);
            }
            if(R>root.val){
                sum+=rangeSumBST(root.right,L,R);
            }
        }
        return sum;
    }
}
__________________________________________________________________________________________________
sample 43388 kb submission
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
    int sum;
    public int rangeSumBST(TreeNode root, int L, int R) {
        sum = 0;
        // rangeSumHelper(root, L, R);
        Queue<TreeNode> q = new LinkedList();
        q.add(root);
        while(!q.isEmpty()){
            TreeNode n = q.poll();
            if(n != null){
                if(n.val >= L && n.val <= R){
                    sum += n.val;
                }

                if(n.val > L){
                    q.add(n.left);
                }
                if(n.val < R){
                    q.add(n.right);
                }
            }
        }
        return sum;
    }
}
__________________________________________________________________________________________________
