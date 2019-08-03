__________________________________________________________________________________________________
sample 51 ms submission
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class CBTInserter {
    TreeNode root;
    Queue<TreeNode> queue;
    public CBTInserter(TreeNode root) {
        this.root = root;
      
        queue = new LinkedList();
        queue.offer(root);

        // BFS to populate deque
        while (!queue.isEmpty()) {
           
            TreeNode node =  queue.peek();
            if (node.left == null || node.right == null) {
                if(node.left !=null) {
                    queue.offer(node.left);
                }
                break; 
            }
            queue.poll();  
            if (node.left != null)
                queue.offer(node.left);
            if (node.right != null)
                queue.offer(node.right);
        }
    }

    public int insert(int v) {
        TreeNode node = queue.peek();
        TreeNode newNode = new TreeNode(v);
        queue.add(newNode);
        if (node.left == null)
            node.left = newNode;
        else {
            queue.poll();
            node.right= newNode;
            
        }

        return node.val;
    }

    public TreeNode get_root() {
        return root;
    }
}

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode param_2 = obj.get_root();
 */
__________________________________________________________________________________________________
sample 38216 kb submission
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class CBTInserter {
    TreeNode root;
    Deque<TreeNode> deque;
    public CBTInserter(TreeNode root) {
        this.root = root;
        deque = new LinkedList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        
        while(!queue.isEmpty()) {
            TreeNode cur = queue.poll();
            if(cur.left == null || cur.right == null) deque.offerLast(cur);
            if(cur.left != null) queue.offer(cur.left);
            if(cur.right != null) queue.offer(cur.right);
        }
    }
    
    public int insert(int v) {
      TreeNode cur = deque.peekFirst();
      deque.offerLast(new TreeNode(v));
      if(cur.left == null) cur.left = deque.peekLast();
      else {
          cur.right = deque.peekLast();
          deque.pollFirst();
      }
      return cur.val;
    }
    
    public TreeNode get_root() {
        return root;
    }
}

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode param_2 = obj.get_root();
 */
__________________________________________________________________________________________________
