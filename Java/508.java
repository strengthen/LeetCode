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
    HashMap<Integer, Integer> map;
    List<Integer> maxSums;
    int maxOccurrences;
    
    public int[] findFrequentTreeSum(TreeNode root) {
        map = new HashMap<Integer, Integer>();
        maxSums = new ArrayList<Integer>();
        findFrequentTreeSumHelper(root);
        
        int[] result = new int[maxSums.size()];
        for (int i = 0; i < maxSums.size(); i++)
        {
            result[i] = maxSums.get(i);
        }
        
        return result;
    }
    
    public int findFrequentTreeSumHelper(TreeNode root)
    {
        if (root == null)
        {
            return 0;
        }
        
        int currentSum = root.val;
        
        if (root.left != null)
        {
            currentSum += findFrequentTreeSumHelper(root.left);
        }
        
        if (root.right != null)
        {
            currentSum += findFrequentTreeSumHelper(root.right);
        }
        
        int numOccurrences = map.getOrDefault(currentSum, 0)+1;
        
        if (numOccurrences == maxOccurrences)
        {
            maxSums.add(currentSum);
        }
        else if (numOccurrences > maxOccurrences)
        {
            maxOccurrences = numOccurrences;
            maxSums = new ArrayList<Integer>();
            maxSums.add(currentSum);
        }
        
        map.put(currentSum, numOccurrences);
        return currentSum;
    }
}
__________________________________________________________________________________________________
sample 38136 kb submission
public class Solution {
    Map<Integer, Integer> sumToCount;
    int maxCount;
    
    public int[] findFrequentTreeSum(TreeNode root) {
        maxCount = 0;
        sumToCount = new HashMap<Integer, Integer>();
        
        postOrder(root);
        
        List<Integer> res = new ArrayList<>();
        for (int key : sumToCount.keySet()) {
            if (sumToCount.get(key) == maxCount) {
                res.add(key);
            }
        }
        
        int[] result = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            result[i] = res.get(i);
        }
        return result;
    }
    
    private int postOrder(TreeNode root) {
        if (root == null) return 0;
        
        int left = postOrder(root.left);
        int right = postOrder(root.right);
        
        int sum = left + right + root.val;
        int count = sumToCount.getOrDefault(sum, 0) + 1;
        sumToCount.put(sum, count);
        
        maxCount = Math.max(maxCount, count);
        
        return sum;
    }
}
__________________________________________________________________________________________________
