__________________________________________________________________________________________________
sample 56 ms submission
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class BSTIterator {
    LinkedList<TreeNode> tree;
    TreeNode head = null;
    public BSTIterator(TreeNode root) {
        tree = new LinkedList<TreeNode>();
        if(root != null){
            
            tree = inorder(tree, root);
            head = tree.peek();
        }
            
    }
    public LinkedList<TreeNode> inorder(LinkedList<TreeNode> tree, TreeNode node){
        if(node == null)
            return null;
        
        inorder(tree, node.left);
        tree.add(node);
        inorder(tree, node.right);
        return tree;
    }
    
    /** @return the next smallest number */
    public int next() {
        TreeNode node = head;
        tree.poll();
        head = tree.peek();
        return node.val;
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        if(tree.size()>=1)
            return true;
        return false;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
__________________________________________________________________________________________________
sample 43760 kb submission
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class BSTIterator {
    private Stack<TreeNode> stack = new Stack<TreeNode>();
    
    public BSTIterator(TreeNode root) {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !stack.isEmpty();
    }

    /** @return the next smallest number */
    public int next() {
        TreeNode tmpNode = stack.pop();
        pushAll(tmpNode.right);
        return tmpNode.val;
    }
    
    private void pushAll(TreeNode node) {
        for (; node != null; stack.push(node), node = node.left);
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
__________________________________________________________________________________________________
