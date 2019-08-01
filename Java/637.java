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
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> res = new ArrayList<>();
        if (root == null) return res;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        bfs(res, queue);
        return res;
    }
    
    private void bfs(List<Double> res, Queue<TreeNode> queue) {
        if (queue.isEmpty()) return;
        int size = queue.size();
        double sum = 0;
        int curSize = size;
        while (curSize -- > 0) {
            TreeNode tn = queue.poll();
            sum += tn.val;
            if (tn.left != null) queue.add(tn.left);
            if (tn.right !=  null) queue.add(tn.right);
        }
        res.add(sum / size);
        bfs(res, queue);
    }
}
__________________________________________________________________________________________________
sample 40104 kb submission
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
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> result = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        if(root != null) 
            queue.add(root);
        levelOrder(queue, result, queue.size());
        return result;
    }
    public void levelOrder(Queue<TreeNode> queue, List<Double> result, int size) {
        if(queue.isEmpty())
            return;
        int count = size; long sum = 0;
        while(size > 0) {
            TreeNode temp = queue.poll();
            size--;
            if(temp.left != null)
                queue.add(temp.left);
            if(temp.right != null)
                queue.add(temp.right);
            sum += temp.val;
        }
        result.add((double)(sum)/count);
        levelOrder(queue, result, queue.size());
    }
}
__________________________________________________________________________________________________
