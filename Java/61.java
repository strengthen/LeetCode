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
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) return null;
        ListNode start = head;
        int count = 1;
        while(start.next != null) {
            start = start.next;
            count++;
        }
        start.next = head;
        for(int i = count - k % count - 1; i > 0; i--) {
            head = head.next;
        }
        start = head.next;
        head.next = null;
        return start;
    }
}
__________________________________________________________________________________________________
sample 35348 kb submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null||k==0) return head;
        
        int len = 0;
        ListNode p = head;
        for(int i = 0;i < k; ++i){
            if(p!=null){
                ++len;
                p = p.next;
            }else{
                break;
            }
        }
        if(len==k&&p==null){
            return head;
        }
        
        
        if(len<k){
            k %= len;
            if(k==0){
                return head;
            }
            p = head;
            for(int i = 0;i < k; ++i){
                p = p.next;
            }
        }
        ListNode b = head;
        while(p.next!=null){
            p = p.next;
            b = b.next;
        }
        p.next = head;
        ListNode r = b.next;
        b.next = null;
        return r;
    }
}
__________________________________________________________________________________________________
