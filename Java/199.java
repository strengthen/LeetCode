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
    int max=-1;
    List<Integer> ls;
    public List<Integer> rightSideView(TreeNode root) {
        ls=new ArrayList<Integer>();
        if(root==null)
            return ls;
        
        rightSide(root,0);
        return ls;
    }
    
    public void rightSide(TreeNode root,int level)
    {
        if(root==null)
            return;
        if(max<level)
        {
            ls.add(root.val);
            max=level;
        }
        rightSide(root.right,level+1);
        rightSide(root.left,level+1);
    }
}
__________________________________________________________________________________________________
sample 34548 kb submission
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
    public List<Integer> rightSideView(TreeNode root) {
        
        Map<Integer,List<Integer>> result = new HashMap<Integer,List<Integer>> ();
        
        getNodeList(result, root, 0);
        
        //System.out.println(result.get(1).get(0));
        
        List<Integer> ans = new ArrayList<>();
        
        for (List<Integer> list : result.values()) {
            ans.add(list.get(list.size()-1));
        }
              
        return ans;
    }
    
    private void getNodeList(Map<Integer,List<Integer>> result, TreeNode root, int level){
        
        if(root==null) return;
        
        if(result.containsKey(level)){
            result.get(level).add(root.val);
        }else{
            List<Integer> set = new ArrayList<>();
            set.add(root.val);
            result.put(level, set);
        }
        
        //result.get(level).add(root.val);
        level++;
        getNodeList(result, root.left, level);
        getNodeList(result, root.right, level);
    }
}
__________________________________________________________________________________________________
