__________________________________________________________________________________________________
1ms
class Solution {
    public boolean twoSumBSTs(TreeNode root1, TreeNode root2, int target) {
        if(root1==null)
            return false;
        if(check(root2,target-root1.val) || twoSumBSTs(root1.left,root2,target) || twoSumBSTs(root1.right,root2,target))
            return true;   
        return false;
    }
    public boolean check(TreeNode node,int target)
    {
        while(node!=null)
        {
            if(node.val==target) return true;
            if(node.val <target) node=node.right;
            else node=node.left;
        }
        return false;
    }    
}
__________________________________________________________________________________________________
sample 6 ms submission
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
    public boolean twoSumBSTs(TreeNode root1, TreeNode root2, int target) {
        Set<Integer> set1 = treeToSet(root1, new HashSet<Integer>());
        Set<Integer> set2 = treeToSet(root2, new HashSet<Integer>());
        for(int x1 : set1) {
            if(set2.contains(target - x1)) {
                return true;
            }
        }
        return false;
    }
    
    private Set<Integer> treeToSet(TreeNode node, Set<Integer> acc) {
        if(node != null) {
            acc.add(node.val);
            treeToSet(node.left, acc);
            treeToSet(node.right, acc);
        }
        return acc;
    }
}
__________________________________________________________________________________________________
