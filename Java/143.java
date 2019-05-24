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
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) {
            return;
        }
        ListNode slow = head, fast = head, prev = null;
        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        if (fast != null) {
            prev = slow;
            slow = slow.next;
        }
        prev.next = null;
        prev = null;
        while (true) {
            ListNode tmp = slow.next;
            slow.next = prev;
            prev = slow;
            if (tmp != null) {
                slow = tmp;
            } else {
                break;
            }
        }
        
        ListNode cur = head, next = slow;
        while (cur != null) {
            ListNode tmp = cur.next;
            cur.next = next;
            cur = cur.next;
            next = tmp;
        }
    }
}
__________________________________________________________________________________________________
sample 35544 kb submission
public class Solution {
    public void reorderList(ListNode head)
    {
        if(head == null || head.next == null)
            return;
        ListNode slow = head;
        ListNode fast = head;
        while(fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode newHead = slow.next;
        slow.next = null;
        ListNode pre = null;
        ListNode cur = newHead;
        while(cur != null)
        {
            ListNode next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        ListNode head1 = head;
        ListNode head2 = pre;
        while(head1!= null && head2 != null)
        {
            ListNode head2Next = head2.next;
            head2.next = head1.next;
            head1.next = head2;
            head1 = head2.next;
            head2 = head2Next;
        }
    }
}
__________________________________________________________________________________________________
