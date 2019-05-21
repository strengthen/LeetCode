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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        dfs(res, root, 0);
        return res;
    }
    
    private void dfs(List<List<Integer>> res, TreeNode root, int level) {
        if (root == null) {
            return;
        }
        List<Integer> currList;
        if (level >= res.size()) {
            currList = new ArrayList<>();
            res.add(currList);
        } else {
            currList = res.get(level);
        }
        currList.add(root.val);
        dfs(res, root.left, level + 1);
        dfs(res, root.right, level + 1);
    }
}
__________________________________________________________________________________________________
sample 34640 kb submission
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> levOrd = new LinkedList<List<Integer>>();
        if (root == null)
            return levOrd;
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        Map<TreeNode,TreeNode> map = new HashMap<TreeNode,TreeNode>();
        queue.offer(root);
        LinkedList<Integer> currentList = new LinkedList<Integer>();
        LinkedList<TreeNode> currListNode = new LinkedList<TreeNode>();
        while(!queue.isEmpty()){
            TreeNode currentNode = queue.poll();
            if (map.get(currentNode)!=null && currListNode.contains(map.get(currentNode))){
                levOrd.add(currentList);
                currentList = new LinkedList<Integer>();
                currListNode = new LinkedList<TreeNode>();
                currentList.add(currentNode.val);
                currListNode.add(currentNode);
            }else{
                currentList.add(currentNode.val);
                currListNode.add(currentNode);
            }
            if (queue.isEmpty()){
                levOrd.add(currentList);
                currentList = new LinkedList<Integer>();
                currListNode = new LinkedList<TreeNode>();
            }
            
            if (currentNode.left!=null){
                map.put(currentNode.left, currentNode);
                queue.offer(currentNode.left);
            }
            if (currentNode.right!=null){
                map.put(currentNode.right, currentNode);
                queue.offer(currentNode.right);
            }
            
        }
        return levOrd;        
    }
}
__________________________________________________________________________________________________
