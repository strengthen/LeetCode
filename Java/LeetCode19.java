__________________________________________________________________________________________________
0ms
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
     public ListNode removeNthFromEnd(ListNode head, int n) {
        int count = 0;
        ListNode p;
        p = head;
        while(p!=null){
            count++;
            p = p.next;
        }
        if(count - n==0){
            return head.next;
        }
        p = head;
        while(count-n!=1){
            p = p.next;
            count--;
        }
        p.next = p.next.next;
        return head;
    }
}
__________________________________________________________________________________________________
1ms
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null) {
            return null;
        }
        Stack<ListNode> stack = new Stack<ListNode>();
        ListNode node = head;
        while(node != null) {
            stack.push(node);
            node = node.next;
        }
        
        ListNode top = null;
        for (int i=0;i<n;i++) {
            top = stack.pop();
        }
        
        ListNode prev = stack.empty() ? null : stack.pop();
        if (prev == null) {
            return head.next;
        }
        
        prev.next = top.next;
        top.next = null;
        return head;
        
    }
}
__________________________________________________________________________________________________
3ms
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
       ListNode ret = head;
        ListNode pre_start = head;
        ListNode start = head;
        ListNode end = start;
        for (int i=1;i<=n;i++) {
            if (end == null) return ret;
            end = end.next;
        }
        if (end==null)  return ret.next;
        while (end!=null) {
             pre_start = start;
            start = start.next;
            end = end.next;
        }
        //if (pre_start == head)  return ret.next;
        pre_start.next = start.next;
        System.out.println(" " + pre_start.val + " " + start.val);
        return ret;  
    }
}
__________________________________________________________________________________________________
35096 kb
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    private static int getLen(ListNode head) {
        if (head == null)
            return 0;
        return 1 + getLen(head.next);
    }
    
    private ListNode twoPass(ListNode head, int n) {
        // Use a two-pointer solution
        int len = getLen(head);
        int idx = len - n;
        // idx is 0-indexed
        ListNode cur = head;
        ListNode prev = null;
        for (int i = 0; i < idx && cur.next != null; i++) {
            prev = cur;
            cur = cur.next;
        }

        if (prev == null) {
            // first element in list
            head = cur.next;
            cur.next = null;
            return head;
        }

        ListNode t = cur.next;
        cur.next = null;
        prev.next = t;
        return head;
    }
    
    private ListNode onePass(ListNode head, int n) {
        /*ListNode rabbit = head;
        ListNode turtle = head;
        for (int i = 0; i < n && rabbit != null; i++) {
            rabbit = rabbit.next;
            i++;
        }
        ListNode prevTurtle = null;
        while (turtle != null && rabbit != null) {
            prevTurtle = turtle;
            turtle = turtle.next;
            rabbit = rabbit.next;
        }
        
        // turtle should now be on correct node
        if (prevTurtle == null) {
            head = turtle.next;
            turtle.next = null;
            return head;
        }
        ListNode t = turtle.next;
        turtle.next = null;
        prevTurtle.next = t;
        return head;*/
        ListNode rabbit = head;
        ListNode turtle = head;
        for (int i = 0; i < n && rabbit != null; i++) 
            rabbit = rabbit.next;
        
        ListNode prevTurtle = null;
        while (turtle != null && rabbit != null) {
            prevTurtle = turtle;
            turtle = turtle.next;
            rabbit = rabbit.next;
        }
        
        // turtle should now be on correct node
        if (prevTurtle == null) {
            head = turtle.next;
            turtle.next = null;
            return head;
        }
        ListNode t = turtle.next;
        turtle.next = null;
        prevTurtle.next = t;
        return head;
    }
    
    public ListNode removeNthFromEnd(ListNode head, int n) {
        return onePass(head, n);
    }
}
__________________________________________________________________________________________________
35124 kb
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {

        if(head == null || head.next == null)
        {
            return null;
        }
        int i = getNodeIndex(head,n);
        if(i == n)
        {
            head = head.next;
        }
        return head;
    }
    
    private int getNodeIndex(ListNode node, int n)
    {        
        if(node.next == null)
        {
            return 1;
        }

        int i = 1 + getNodeIndex(node.next,n);

        if( n == i-1)
        {
            node.next = node.next.next;
            
            return i ;
        }            
        
        return i;
    }
}
__________________________________________________________________________________________________
