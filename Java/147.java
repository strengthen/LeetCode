__________________________________________________________________________________________________
sample 1 ms submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode merge(ListNode l1, ListNode l2){
           if(l1 == null) return l2;
           if(l2 == null) return l1;
       
            if(l1.val < l2.val){
                l1.next = merge(l1.next,l2);
                return l1;
            }else
             l2.next = merge(l1,l2.next);
                return l2;
    }    
    
    public ListNode insertionSortList(ListNode head) {
        if(head == null || head.next == null ) return head;
        ListNode slow = head,fast = head;
        /* find the middle of the list */
        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        fast = slow.next; 
        slow.next = null;
        slow = head;
        slow = insertionSortList(slow); 
        fast = insertionSortList(fast);
        
        return merge(slow,fast);
    }
}
__________________________________________________________________________________________________
sample 34596 kb submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode insertionSortList(ListNode head) {
        ListNode newHead = new ListNode(0);
        newHead.next = head;

        ListNode headPointer = newHead;
        while (headPointer.next != null) {
            ListNode min = null;
            ListNode prev = null;
            ListNode pointer = headPointer;
            while (pointer.next != null) {
                if (min == null) {
                    min = pointer.next;
                    prev = pointer;
                } else {
                    if (pointer.next.val < min.val) {
                        min = pointer.next;
                        prev = pointer;
                    }
                }
                pointer = pointer.next;
            }
            if (min != null) {
                prev.next = prev.next.next;
                min.next = headPointer.next;
                headPointer.next = min;
            }
            headPointer = headPointer.next;
        }
        
        return newHead.next;
    }
}
__________________________________________________________________________________________________
