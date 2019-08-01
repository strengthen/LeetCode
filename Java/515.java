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
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        helper(root, 0, res);
        return res;
    }
    public void helper(TreeNode root, int depth, List<Integer> res){
        if(root == null) return ;
        if(res.size() == depth) {
            res.add(root.val);
        }else{
            res.set(depth, Math.max(root.val, res.get(depth)));
        }
        helper(root.left, depth+1, res);
                    helper(root.right, depth+1, res);
    }
}
__________________________________________________________________________________________________
sample 38012 kb submission
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
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> largest = new ArrayList<>();
        if (root == null) return largest;
        else {
            helper(root, largest);
            return largest;
        }
    }
    public void helper(TreeNode root, List lst) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (queue.size() > 0) {
            int max = Integer.MIN_VALUE;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode removed = queue.poll();
                //System.out.println(removed.val);
                if (removed.val > max) max = removed.val;
                if (removed.left != null) queue.add(removed.left);
                if (removed.right != null) queue.add(removed.right);
            }
            //System.out.println(max);
            lst.add(max);
        }
    }
}
__________________________________________________________________________________________________
