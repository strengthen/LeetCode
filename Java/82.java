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
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return null;
        ListNode dummy = new ListNode(0 == head.val ? 1 : 0);
        dummy.next = head;
        ListNode pre = dummy, cur = head;
        ListNode ptr = dummy;
        while (cur != null && cur.next != null) {
            if (pre.val != cur.val && cur.val != cur.next.val) {
                ptr.next = cur;
                ptr = ptr.next;
            }
            pre = cur;
            cur = cur.next;
        }
        if (pre.val != cur.val) {
            ptr.next = cur;
            ptr = ptr.next;
        }
        ptr.next = null;
        return dummy.next;
    }
}
__________________________________________________________________________________________________
sample 34244 kb submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        HashMap<Integer,Integer> map = new HashMap<>();
        for(ListNode i = head;i!=null;i = i.next){
            map.put(i.val,map.getOrDefault(i.val,0)+1);
        }
        
        for(ListNode i = dummyHead;i!=null;i = i.next){
            ListNode g = i.next;
            while(g!=null && map.get(g.val)>1){
                g=g.next;
            }
            i.next = g;
        }
        return dummyHead.next;
    }
}
__________________________________________________________________________________________________
