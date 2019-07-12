__________________________________________________________________________________________________
Runtime: 0 ms
Memory Usage: 38.4 MB
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
    public TreeNode deleteNode(TreeNode root, int key) {
        TreeNode prevNode = null, cur = root;
        boolean leftChild = false, nodeFound = false;
        
        while(cur != null){
            if(cur.val == key){
                nodeFound = true;
                break;
            }
            
            prevNode = cur;
            if(cur.val > key){
                leftChild = true;
                cur = cur.left;
            }
            else{
                leftChild = false;
                cur = cur.right;
            }
        }
        
        if(!nodeFound){
            return root;
        }
        
        if(prevNode == null){
            return deleteNode(cur);
        }
        
        if(leftChild){
            prevNode.left = deleteNode(cur);
        }
        else{
            prevNode.right = deleteNode(cur);
        }
        
        return root;
    }
    
    private TreeNode deleteNode(TreeNode node){
        if(node.left == null && node.right == null){
            return null;
        }
        
        if(node.left != null && node.right != null){
            TreeNode minRightSubtreeNode = findAndDeleteMinRightSubtree(node);
            node.val = minRightSubtreeNode.val;
        }
        else if(node.left != null){
            node = node.left;
        }
        else{
            node = node.right;
        }
        
        return node;
    }
    
    private TreeNode findAndDeleteMinRightSubtree(TreeNode node){
        TreeNode prevNode = node;
        node = node.right;
        boolean rightChild = node.left == null;
        
        while(node.left != null){
            prevNode = node;
            node = node.left;
        }
        
        if(rightChild){
            prevNode.right = node.right;
        }
        else{
            prevNode.left = node.right;
        }
        
        node.right = null;
        return node;
    }
}
__________________________________________________________________________________________________
sample 38432 kb submission
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
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) {
            return null;
        } else if (key < root.val) {
            root.left = deleteNode(root.left, key);
        } else if (key > root.val) {
            root.right = deleteNode(root.right, key);
        } else {
            if (root.right == null) {
                return root.left;
            }
            
            if (root.left == null) {
                return root.right;
            }
            
            root.val = findMin(root.right);
            root.right = deleteNode(root.right, root.val);
        }
        
        return root;
    }
    
    private int findMin(TreeNode root) {
        while (root.left != null) {
            root = root.left;
        }
        
        return root.val;
    }
}
__________________________________________________________________________________________________
