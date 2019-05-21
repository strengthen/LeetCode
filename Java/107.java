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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
         List<List<Integer>> result = new ArrayList<>();
    travelTree(0, root, result);
    List<List<Integer>> reverseRst = new ArrayList<>();
    for (int i = 0; i < result.size(); i++) {
        reverseRst.add(result.get(result.size() - i - 1));
    }
    return reverseRst;
}

private void travelTree(int level, TreeNode root, List<List<Integer>> result) {
    if (root == null) return;
    if (result.size() <= level) result.add(new ArrayList<>());
    result.get(level).add(root.val);
    travelTree(level + 1, root.left, result);
    travelTree(level + 1, root.right, result);
  }
}
__________________________________________________________________________________________________
sample 34632 kb submission
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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> ans = new LinkedList<>();
        traverse(root, 0, ans);
        return ans;
    }
    
    public void traverse(TreeNode t, int level, List<List<Integer>> ans) {
        if(t == null) return;
        if(ans.size() == level)
        {
            List<Integer> newList = new LinkedList();
            ans.add(0, newList);
        }
        
        traverse(t.left, level + 1, ans);
        traverse(t.right, level + 1, ans);
        List<Integer> old = ans.get(ans.size() - 1 - level);
        old.add(t.val);
    }
}
__________________________________________________________________________________________________
