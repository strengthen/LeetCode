__________________________________________________________________________________________________
sample 3 ms submission
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
    public int pathSum(TreeNode root, int sum) {
        // key = prefix-sum, value = number of the key 
        HashMap<Integer, Integer> map = new HashMap();
        map.put(0, 1);
        int[] count = { 0 };
        helper(root, sum, 0, count, map);
        return count[0];
    }

    private void helper(TreeNode root, int target, int prefixSum, int[] count, HashMap<Integer, Integer> map) {
        if (root == null) {
            return;
        }
        
        prefixSum += root.val;
        
        // update global count
        if (map.containsKey(prefixSum - target)) {
            count[0] += map.get(prefixSum - target);
        }

        // add to map
        Integer num = map.get(prefixSum);
        if (num == null) {
            map.put(prefixSum, 1);
        } else {
            map.put(prefixSum, num + 1);
        }

        helper(root.left, target, prefixSum, count, map);
        helper(root.right, target, prefixSum, count, map);
        
        if (num == null) {
            map.put(prefixSum, 0);
        } else {
            map.put(prefixSum, num);
        }
    }
}
__________________________________________________________________________________________________
sample 36896 kb submission
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
    
    public int pathSum(TreeNode root, int sum) {
        if (root == null) {
            return 0;
        }
        Map<Integer, Integer> preSumCount = new HashMap<>();
        preSumCount.put(0, 1);
        return dfs(root, sum, preSumCount, 0);
    }
    
    private int dfs(TreeNode node, int tgt, Map<Integer, Integer> preSumCount, int preSum) {
        preSum += node.val;

        int result = 0;
        // 以我为结尾的子数组中，有多少的和等于tgt
        result += preSumCount.getOrDefault(preSum - tgt, 0);
        // 进来时加我
        preSumCount.put(preSum, preSumCount.getOrDefault(preSum, 0) + 1);
        
        // 以我的孩子为结尾的子数组中，有多少的和等于tgt
        if (node.left != null) {
            result += dfs(node.left, tgt, preSumCount, preSum);
        }
        if (node.right != null) {
            result += dfs(node.right, tgt, preSumCount, preSum);
        }
        // 离开时删我
        preSumCount.put(preSum, preSumCount.get(preSum) - 1);
        if (preSumCount.get(preSum) == 0) {
            preSumCount.remove(preSum);
        }
        return result;
    }
}
__________________________________________________________________________________________________
