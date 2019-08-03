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
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        List<Integer> res = new ArrayList<Integer>();
        
        Deque<TreeNode> stack = new ArrayDeque<TreeNode>();
        TreeNode cur = root, lastVisited = null, peek = null;
        while((stack.size() > 0 || cur != null)) {
            if(cur != null) {
                stack.push(cur);
                if(cur == target) {
                    break;
                }
                
                cur = cur.left;
            } else {
                peek = stack.peek();
                if(peek.right != null && lastVisited != peek.right) {
                    cur = peek.right;
                } else {
                    lastVisited = stack.pop();
                }
            }
        }
        
        int layer = 0;
        lastVisited = null;
        while(stack.size() > 0 && layer <= K) {
            cur = stack.pop();
            preorder(res, cur, K, layer, lastVisited);
            lastVisited = cur;
            ++layer;
        }
        
        return res;
    }
    
    public void preorder(List<Integer>res, TreeNode root, int k, int layer, TreeNode nodeToAvoid) {
        if(root == null) {
            return;
        }
        
        if(layer == k && root != nodeToAvoid) {
            res.add(root.val);
            return;
        }
        
        if(layer < k && root != nodeToAvoid) {
            ++layer;
            preorder(res, root.left, k, layer, nodeToAvoid);
            preorder(res, root.right, k, layer, nodeToAvoid);
        }
    
    }
}
__________________________________________________________________________________________________
sample 36892 kb submission
/**
 * Definition for a binary tree node.
 *  
 */
class Solution {
    
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        List<Integer> nums = new ArrayList<>();
        Map<TreeNode, TreeNode> parentMap = new HashMap<>();
        Set<Integer> seen = new HashSet<>();
        populateParentNodeMap(parentMap, root, null);

        findNodes(parentMap, target, K, 0, seen, nums);
        return nums;
    }

    void populateParentNodeMap(Map<TreeNode, TreeNode> parentMap, TreeNode cur, TreeNode parent) {
        if (cur == null) return;
        parentMap.put(cur, parent);
        populateParentNodeMap(parentMap, cur.left, cur);
        populateParentNodeMap(parentMap, cur.right, cur);
    }


     void findNodes(Map<TreeNode, TreeNode> parentMap, TreeNode target, int k, int level, Set<Integer> seen, List<Integer> nums) {
        if (target == null || level > k || seen.contains(target.val)) return;
        if (level == k) {
            if (!seen.contains(target.val)) nums.add(target.val);
            return;
        }
        level++;
        seen.add(target.val);
        findNodes(parentMap, target.left, k, level, seen, nums);
        findNodes(parentMap, target.right, k, level, seen, nums);
        findNodes(parentMap, parentMap.get(target), k, level, seen, nums);
    }
    
}
__________________________________________________________________________________________________
