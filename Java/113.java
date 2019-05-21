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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> list = new LinkedList<List<Integer>>();
        if(root == null){
            return list;
        }
        List<Integer> list2 = new LinkedList<Integer>();
        pathSum(root, sum, 0, list, list2);
        return list;
    }
    
    public void pathSum(TreeNode root, int sum, int temp, List<List<Integer>> list, List<Integer> list2){
        if(root.left == null && root.right == null && temp+root.val == sum){
            list2.add(root.val);
            list.add(new LinkedList(list2));
            list2.remove(list2.size()-1);
        }
        if(root.left != null){
            list2.add(root.val);
            pathSum(root.left,sum,temp+root.val, list, list2);
            list2.remove(list2.size()-1);
        }
        if(root.right != null){
            list2.add(root.val);
            pathSum(root.right,sum,temp+root.val, list, list2);
            list2.remove(list2.size()-1);
        }
    }
}
__________________________________________________________________________________________________
sample 34972 kb submission
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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        LinkedList<List<Integer>> sol = new LinkedList<List<Integer>>();
        
        solve(root, sum, sol, 0, new LinkedList<Integer>());
        
        return (sol);
    }
    
    private void solve (TreeNode root, int target, LinkedList<List<Integer>> sol, int sum, LinkedList<Integer> partial) {
        if (root == null) {
            return;
        }
        
        sum += root.val;
        partial.add(root.val);
        if (root.left == null && root.right == null) {
            if (sum == target) {
                sol.add(new LinkedList<Integer>(partial));
            }
            partial.removeLast();
            
            return;
        }
        
        solve(root.left, target, sol, sum, partial);
        solve(root.right, target, sol, sum, partial);
        partial.removeLast();
    }
}
__________________________________________________________________________________________________
