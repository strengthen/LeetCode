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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
                List<List<Integer>> res = new ArrayList<>();
        traverse(root, res, 0);
        return res;
    }
    
     private void traverse(TreeNode root, List<List<Integer>> res, int level) {
        if(root == null) return;

        if(res.size() <= level){
            List<Integer> l = new LinkedList<>();
            res.add(l);
        }
        List<Integer> collection = res.get(level);
        if(level % 2 == 0){
            collection.add(root.val);
        }else{
            collection.add(0, root.val);
        }

        traverse(root.left, res, level + 1);
        traverse(root.right, res, level + 1);
    }
}
__________________________________________________________________________________________________
sample 34396 kb submission
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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        
        Queue<TreeNode> q = new LinkedList<>();
        List<List<Integer>> l = new ArrayList<>();
        if(root == null) return new ArrayList<>();
        q.add(root);
        while(!q.isEmpty()){
            int size = q.size();
            List<Integer> res = new LinkedList<>();
            for(int i =0 ; i < size;i++){
                TreeNode temp = q.poll();
                res.add(temp.val);
                if(temp.left != null){
                    q.add(temp.left);
                }
                if(temp.right != null){
                    q.add(temp.right);
                }
                
            }
            l.add(res);
        }
        
        for(int j =1 ; j < l.size() ; j++){
            if(j % 2 == 1){
                Collections.reverse(l.get(j));
            }
        }
        return l;        
    }
}
__________________________________________________________________________________________________
