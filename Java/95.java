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
    public List<TreeNode> generateTrees(int n) {
        //在循环中调用递归函数求解子问题。思路是每次一次选取一个结点为根，然后递归求解左右子树的所有结果，最后根据左右子树的返回的所有子树，依次选取然后接上（每个左边的子树跟所有右边的子树匹配，而每个右边的子树也要跟所有的左边子树匹配，总共有左右子树数量的乘积种情况），构造好之后作为当前树的结果返回。
        List<TreeNode> list=new ArrayList<TreeNode>();
        if(n<1) return list;
        return helper(1,n);
    }
    
    private ArrayList<TreeNode> helper(int left, int right){
        ArrayList<TreeNode> res = new ArrayList<TreeNode>();
        if (left > right){
            res.add(null);
            return res;
        }
        for (int i = left; i <= right; i++){
            ArrayList<TreeNode> lefts = helper(left, i-1);//以i作为根节点，左子树由[1,i-1]构成
            ArrayList<TreeNode> rights = helper(i+1, right);//右子树由[i+1, n]构成
            for (int j = 0; j < lefts.size(); j++){
                for (int k = 0; k < rights.size(); k++){
                    TreeNode root = new TreeNode(i);
                    root.left = lefts.get(j);
                    root.right = rights.get(k);
                    res.add(root);//存储所有可能行
                }
            }
        }
        return res;
    }  
}
__________________________________________________________________________________________________
sample 37000 kb submission
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
    public List<TreeNode> generateTrees(int n) {
        if(n==0)
            return new ArrayList<TreeNode>();
        return generate(1,n);
    }
    
    private List<TreeNode> generate(int start, int end)
    {
        List<TreeNode> ans = new ArrayList();
        if(start>end)
        {
            ans.add(null);
            return ans;
        }
        if(start==end)
        {
            ans.add(new TreeNode(start));
            return ans;
        }
        
        for(int i=start; i<=end; i++)
        { 
            List<TreeNode> left = generate(start,i-1);
            List<TreeNode> right = generate(i+1, end);
            for(TreeNode l : left)
            {
                for(TreeNode r : right)
                {
                    TreeNode node = new TreeNode(i);
                    node.left = l;
                    node .right  = r;
                    ans.add(node);
                }
            }
        }
        return ans;
    }
}
__________________________________________________________________________________________________
