__________________________________________________________________________________________________
sample 0 ms submission
/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;
    public Node random;

    public Node() {}

    public Node(int _val,Node _next,Node _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
    public Node copyRandomList(Node head) {
        if( head == null )return head;
        Node cur = head;
        // Copy each node's and link these copies to the current List.
        while( cur != null ){
            Node nextNode = cur.next;
            Node copy = new Node(cur.val);
            copy.next = nextNode;
            cur.next = copy;
            cur = nextNode;
        }
        // Create the random pointer.
        cur = head;
        while( cur != null ){
            if( cur.random != null ){
                cur.next.random = cur.random.next;
            }
            cur = cur.next.next;
        }
        // Cut the copied Node list from the original
        cur = head;
        Node rst = cur.next;
        while( cur != null ){
            Node nextNode = cur.next.next;
            if( nextNode != null ){
                cur.next.next = nextNode.next;
            }
            cur.next = nextNode;
            cur = nextNode;
        }
            
        return rst;
    }
}
__________________________________________________________________________________________________
sample 31288 kb submission
/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;
    public Node random;

    public Node() {}

    public Node(int _val,Node _next,Node _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
    HashMap<Node,Node> hm ;
    public Node copyRandomList(Node head) {
        hm = new HashMap();
        if(head == null){
            return null;
        }
        return helper(head);
    }
    
    private Node helper(Node head){
        if(head == null){
            return head;
        }
        if(hm.containsKey(head)){
            return hm.get(head);
        }
        Node newNode = new Node(head.val);
        hm.put(head,newNode);
 
        newNode.next = helper(head.next);
        newNode.random = helper(head.random);
        return newNode;
    }
}
__________________________________________________________________________________________________
