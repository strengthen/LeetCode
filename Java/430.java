__________________________________________________________________________________________________
sample 0 ms submission
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;

    public Node() {}

    public Node(int _val,Node _prev,Node _next,Node _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
    public Node flatten(Node head) {
        Node h = head;
        while (head != null) {
            if (head.child == null) {
                head = head.next;
                continue;
            }
            Node p = head;
            Node temp = head.next;
            head.next = head.child;
            head.child.prev = head;
            head.child = null;
            while (head.next != null) {
                head = head.next;
            }
            
            if (temp != null) {
                head.next = temp;
                temp.prev = head;
                head = p;
            }
            
        }
        return h;
    }
}
__________________________________________________________________________________________________
sample 36808 kb submission
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;

    public Node() {}

    public Node(int _val,Node _prev,Node _next,Node _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
    public Node flatten(Node head) {
        Node dummy = head;        
        while(head != null) {
            if(head.child == null) {
                head = head.next;
                continue;
            }
            // Save child node
            Node child = head.child;
            // Traverse child to find last node
            while(child.next != null) {
                child = child.next;
            }
            // Connect child to next node
            child.next = head.next;
            // Connect next node to child
            if(head.next != null) {
                head.next.prev = child;
            }
            //Remove child from head and point it to the begining of child
            head.next = head.child;
            head.next.prev = head;
            head.child = null;

        }
        return dummy;        
    }
}
__________________________________________________________________________________________________
