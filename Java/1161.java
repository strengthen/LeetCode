__________________________________________________________________________________________________
sample 8 ms submission
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
    public int maxLevelSum(TreeNode root) {
        // root is guaranteed to be not null
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int level = 0, max = 0x80000000, curLevel = 0;
        while (!q.isEmpty()) {
            int size = q.size(), sum = 0;
            curLevel++;
            for (int i = 0; i < size; i++) {
                TreeNode t = q.poll();
                sum += t.val;
                if (t.left != null) q.add(t.left);
                if (t.right != null) q.add(t.right);
            }
            if (sum > max) {
                max = sum;
                level = curLevel;
            }
        }
        return level;
    }
}
__________________________________________________________________________________________________
sample 9 ms submission
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
    public int maxLevelSum(TreeNode root) {
        int resLevel = 1, max = root.val, level = 1;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        
        while (!q.isEmpty()) {
            int size = q.size(), sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode curr = q.poll();
                sum += curr.val;
                if (curr.left != null) q.offer(curr.left);
                if (curr.right != null) q.offer(curr.right);
            }
            if (sum > max) {
                max = sum;
                resLevel = level;
            }
            level++;
        }
        return resLevel;
    }
}
__________________________________________________________________________________________________
