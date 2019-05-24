__________________________________________________________________________________________________
sample 0 ms submission
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (null == head || null == head.next)
            return null;
        ListNode p, q;
        p = head.next;
        q = head.next.next;
        while (q != null && p != q) {
            p = p.next;
            if (q.next == null)
                q = null;
            else 
                q = q.next.next;
        }
        if (q == null)
            return null;
        p = head;
        while (p != q) {
            p = p.next;
            q = q.next;
        }
        return p;
    }
}
__________________________________________________________________________________________________
sample 31436 kb submission
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode root = new ListNode(0);
        root.next = head;
        ListNode p1 = root;
        ListNode p2 = root;
        ListNode p;
        while (true) {
            if (p1 != null && p1.next != null && p1.next.next != null) {
                p1 = p1.next.next;
                p2 = p2.next;
            } else {
                
                System.gc();
                return null;
            }
            if (p1 == p2) {
                p = p1;
                break;
            }
        }
        ListNode h = root;
        while (true) {
            h = h.next;
            p = p.next;
            if (h == p) {
                System.gc();
                return h;
            }
        }
    }
}
__________________________________________________________________________________________________
