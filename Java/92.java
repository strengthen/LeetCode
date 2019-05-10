__________________________________________________________________________________________________
sample 0 ms submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    //Time: O(n), Space: O(1)
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null || head.next == null || m == n) {
            return head;
        }
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode prev = dummy;
        for (int i = 1; i < m; i++) {
            prev = prev.next;
        }
        prev.next = reverse(prev.next, n - m + 1);
        return dummy.next;
    }
    
    private ListNode reverse(ListNode head, int k) {
        ListNode tail = head;
        ListNode prev = null;
        for (int i = 0; i < k; i++) {
            ListNode temp = head.next;
            head.next = prev;
            prev = head;
            head = temp;
        }
        tail.next = head;
        return prev;
    }
}
__________________________________________________________________________________________________
sample 34152 kb submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        
        ListNode curr = dummy,
                 tail = dummy;

        int i;

        for (i = 0; i < m - 1; ++i) {
            curr = curr.next;
        }
        
        for (i = 0; i < n; ++i) {
            tail = tail.next;
        }
        
        while (curr.next != tail) {
            ListNode tmp = curr.next;
            curr.next = tmp.next;
            tmp.next = tail.next;
            tail.next = tmp;
        }
        
        return dummy.next;
    }
}
__________________________________________________________________________________________________
