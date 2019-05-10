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
        if(head == null || head.next == null)return head;
        head.next = deleteDuplicates(head.next);
        return head.val == head.next.val ? head.next : head;
    }
}
__________________________________________________________________________________________________
sample 34548 kb submission
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
        ListNode res = head;
        HashSet<Integer> set = new HashSet<Integer>();
        if(head == null) return null;
        set.add(head.val);
        while(head.next != null){
            if(set.contains(head.next.val)){
                head.next = head.next.next;
            }
            else{
                set.add(head.next.val);
                head = head.next;
            }
         }
        return res;
    }
}
__________________________________________________________________________________________________
