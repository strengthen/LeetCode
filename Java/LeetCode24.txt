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
public class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head==null||head.next==null) {
            return head;
        }else {
            int val=head.val;
            head.val=head.next.val;
            head.next.val=val;
            head.next.next=swapPairs(head.next.next);
        }
        return head;
    }
}
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
    public ListNode swapPairs(ListNode head) {
        ListNode n = new ListNode(0);
        n.next = head;
        ListNode pointer = n;
        
        while (pointer != null && pointer.next != null && pointer.next.next != null){
            swapTwoNodes(pointer, pointer.next, pointer.next.next);
            pointer = pointer.next.next;
        }
        
        return n.next;
    }
    
    public void swapTwoNodes(ListNode node0, ListNode node1, ListNode node2){
        node0.next = node2;
        node1.next = node2.next;
        node2.next = node1;
    }
}
__________________________________________________________________________________________________
2ms
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        
        ListNode zero = new ListNode(0);
         System.out.println(zero.next);
        recursion(zero, null , head);
        return zero.next;
    }
    
    public void recursion(ListNode first, ListNode last , ListNode odd){
        
        if(odd == null){
          return;
        }        
        
        ListNode even = odd.next;
       
        if (first.next == null){
                            System.out.println("223");
            if (even == null){
                first.next = odd;
                System.out.println("22");
            }
            else{
                first.next = even;
            }
        }
        
        if (even == null){
            return;
        }
               
        ListNode eventNext = even.next;
        odd.next = eventNext;
        even.next = odd;
        
        if (last != null){
            last.next = even;
        }

        recursion(first, odd, eventNext);        
    }
}
__________________________________________________________________________________________________
34164 kb 
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode cur = head;
        if(cur == null) {
            return cur;
        }
        ListNode swap = head.next;
        if(swap == null) {
            return cur;
        }
        
        cur.next = swapPairs(swap.next);
        swap.next = cur;
        return swap;
    }
}
__________________________________________________________________________________________________
34180 kb
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapHelper(ListNode node){
        if(node == null) return null;
        if(node.next == null) return node;
        ListNode temp = node.next;
        node.next = swapHelper(node.next.next);
        temp.next = node;
        return temp;
    }
    public ListNode swapPairs(ListNode head) {
        return swapHelper(head);
    }
} 
__________________________________________________________________________________________________
