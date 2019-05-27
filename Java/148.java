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
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null)
            return head;

        // quicksort
        ListNode pivot = head;
        ListNode node = head.next;
        ListNode sHead = new ListNode(Integer.MIN_VALUE);
        ListNode lHead = new ListNode(Integer.MIN_VALUE);
        ListNode sCurrent = sHead, lCurrent = lHead, eCurrent = head;
        while (node != null) {
            if (node.val == pivot.val) {
                eCurrent.next = node;
                eCurrent = eCurrent.next;
            } else if (node.val <= pivot.val) {
                sCurrent.next = node;
                sCurrent = sCurrent.next;
            } else {
                lCurrent.next = node;
                lCurrent = lCurrent.next;
            }
            node = node.next;
        }
        sCurrent.next = lCurrent.next = null;
        sHead.next = sortList(sHead.next);
        lCurrent = sortList(lHead.next);
        sCurrent = sHead;
        while (sCurrent.next != null) {
            sCurrent = sCurrent.next;
        }
        sCurrent.next = head;
        eCurrent.next = lCurrent;
        return sHead.next;
    }
}
__________________________________________________________________________________________________
sample 37564 kb submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null)
            return null;
        if (head.next == null)
            return head;
        List<Integer> list = new ArrayList<>();
        while (head.next != null) {
            list.add(head.val);
            head = head.next;
        }
        list.add(head.val);
        Collections.sort(list); 
        return toLinkedList(list);
    }

    private static ListNode toLinkedList(List<Integer> list) {
        if (list == null || list.isEmpty())
            return null;
        
        ListNode head = new ListNode(list.get(0));
        ListNode tail = head;
        for (int i=1; i<list.size(); i++) {
            tail.next = new ListNode(list.get(i));
            tail = tail.next;
        }
        
        return head;
    }
}
__________________________________________________________________________________________________
