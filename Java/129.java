__________________________________________________________________________________________________
sample 0 ms submission

class Solution {
    public int sumNumbers(TreeNode root) {
        if (root == null) return 0;
        return sumNums(root, 0);
    }
    public int sumNums(TreeNode root, int path){
        if (root == null) return 0;
        path = (path*10) + root.val;
        int left = sumNums(root.left, path);
        int right = sumNums(root.right, path);
        if (root.left == null && root.right == null){
            return path;
        }
        return left + right;
    }
}
__________________________________________________________________________________________________
sample 34128 kb submission
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
    public int sumNumbers(TreeNode root) {
        List<int[]> list = helper(root);
        int sum = 0;
        for(int[] i : list){
            sum += i[0];
        }
        return sum;
    }
    
    public List<int[]> helper(TreeNode node) {
        List<int[]> result = new ArrayList<int[]>();
        if(node == null) return result;
        if(node.left == null && node.right == null) {
            result.add(new int[]{node.val, 1});
        } else {
            if(node.left != null) {
                List<int[]> tempResult = helper(node.left);
                for(int i=0; i<tempResult.size(); i++) {
                    int count = tempResult.get(i)[1] * 10;
                    int temp = tempResult.get(i)[0] + node.val * count;
                    result.add(new int[]{temp, count});
                }
            }
            if(node.right != null) {
                List<int[]> tempResult = helper(node.right);
                for(int i=0; i<tempResult.size(); i++) {
                    int count = tempResult.get(i)[1] * 10;
                    int temp = tempResult.get(i)[0] + node.val * count;
                    result.add(new int[]{temp, count});
                }
            }
        }
        return result;
    }

    void merge(List<int[]> result, List<int[]> partial, int value) {
        for(int i=0; i<partial.size(); i++) {
            int count = partial.get(i)[1] * 10;
            int temp = partial.get(i)[0] + value * count;
            result.add(new int[]{temp, count});
        }
    }
}
__________________________________________________________________________________________________
