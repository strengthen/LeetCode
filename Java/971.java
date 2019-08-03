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
    List<Integer> res = new ArrayList<>();
    int i = 0;
    
    public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
        
        if (dfs(root, voyage)) return res;
        
        res.clear();
        res.add(-1);
        return res;
    }
    
    private boolean dfs(TreeNode node, int[] voyage) {
        if (node == null) return true;
        
        if (node.val != voyage[i++]) return false;
        
        if (node.left != null && node.left.val != voyage[i]) {
            res.add(node.val);
            return dfs(node.right, voyage) && dfs(node.left, voyage);
        }
        
        return dfs(node.left, voyage) && dfs(node.right, voyage);
        
    }
}
__________________________________________________________________________________________________
sample 37992 kb submission
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
    public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
        List<Integer> result=new ArrayList<>();
        Stack<TreeNode> stack=new Stack<>();
        stack.push(root);
        int i=0;
        while(stack.size()>0)
        {
            TreeNode node=stack.pop();
            if(node==null)
                continue;
            if(node.val!=voyage[i++])
                return Arrays.asList(-1);
            if(node.right!=null && node.right.val==voyage[i])
            {
                if(node.left!=null)
                {
                    result.add(node.val);
                }
                stack.push(node.left);
                stack.push(node.right);
            }
            else
            {
                stack.push(node.right);
                stack.push(node.left);
            }
                
        }
        return result;
    }
}
__________________________________________________________________________________________________
