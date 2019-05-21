__________________________________________________________________________________________________
sample 0 ms submission
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val,Node _left,Node _right,Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
    public Node connect(Node root) {
        visitNode(root, 0, 0, null);
        return root;
    }
    
    static void visitNode(Node current, int depth, int horizontalDepth, Node parent) {
        if (current == null) return;
        if (Math.pow(2, depth) - 1 == horizontalDepth) {
            current.next = null;
        } else if (horizontalDepth % 2 == 0){
            current.next = parent.right;
        } else {
            current.next = parent.next.left;
        }
        visitNode(current.left, depth + 1, horizontalDepth * 2, current);
        visitNode(current.right, depth + 1, horizontalDepth * 2 + 1, current);
    }
}
__________________________________________________________________________________________________
sample 31784 kb submission
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val,Node _left,Node _right,Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
    
    public Node connect(Node root) {
        Queue<Node> q = new LinkedList<>();
        Node prev = root;
        q.add(prev);
        q.add(null);
        while(!q.isEmpty()){
            Node node = q.remove();
            if(prev == null && node == null){
                break;
            }
            if(prev != null){
                prev.next = node;
            }
            if(node != null){
                q.add(node.left);
                q.add(node.right);
            }
            else{
                q.add(node);
            }
            prev = node;
        }
        return root;
    }
}
__________________________________________________________________________________________________
