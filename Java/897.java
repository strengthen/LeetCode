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
    TreeNode prev = null, head = null;
    public TreeNode increasingBST(TreeNode root) {
        if(root==null) return null;   
        increasingBST(root.left);  
        if(prev!=null) { 
        	root.left=null; // we no  longer needs the left  side of the node, so set it to null
        	prev.right=root; 
        }
        if(head==null) head=root; // record the most left node as it will be our root
        prev=root; //keep track of the prev node
        increasingBST(root.right); 
        return head;
    }
    
}
__________________________________________________________________________________________________
sample 38260 kb submission
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
    
    public TreeNode increasingBST(TreeNode root) {
        List<Integer> vals = new ArrayList();
        thePostOrderTraversal(root, vals);
        // result.val = vals.get(0);
        
        TreeNode ans = new TreeNode(0), cur = ans;
        for (int v: vals) {
            cur.right = new TreeNode(v);
            cur = cur.right;
        }
        return ans.right;
    }
     public void thePostOrderTraversal(TreeNode root,List<Integer> list) {
       if (root == null) return;
        thePostOrderTraversal(root.left, list);
        list.add(root.val);
        thePostOrderTraversal(root.right, list); 
     
    }  
}
__________________________________________________________________________________________________
