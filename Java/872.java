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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> list1 = new ArrayList<Integer>();
        collectLeaf(root1,list1);
        List<Integer> list2 = new ArrayList<Integer>();
        collectLeaf(root2,list2);
        if(list1.size() != list2.size()){
            return false;
        }
        for(int i = 0; i < list1.size(); i ++){
            if (list2.get(i) == null || list1.get(i) != list2.get(i)){
                return false;
            }
        }
        return true;
    }
    private void collectLeaf(TreeNode node, List list){
        if(node == null){
            return;
        }
        if(node.left == null && node.right == null){
            list.add (node.val);
        }
        collectLeaf(node.left, list);
        collectLeaf(node.right,list);
    }
}
__________________________________________________________________________________________________
sample 36512 kb submission
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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        Stack<TreeNode> s1=new Stack<>(), s2=new Stack<>();
        s1.push(root1);
        s2.push(root2);
        while (!s1.isEmpty() && !s2.isEmpty()) {
            if (dfs(s1)!=dfs(s2)) {
                return false;
            }            
        }
        return s1.isEmpty() && s2.isEmpty();
    }
    
    private int dfs(Stack<TreeNode> s) {
        while (true) {
            TreeNode node = s.pop();
            if (node.right!=null) {
                s.push(node.right);
            }
            if (node.left!=null) {
                s.push(node.left);
            }
            if (node.left==null && node.right==null) {
                return node.val;
            }
        }
    }
}
__________________________________________________________________________________________________
