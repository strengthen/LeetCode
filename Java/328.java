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
  public ListNode oddEvenList(ListNode head) {
    if (head == null) {
      return null;
    }
    ListNode evenHead = head.next;
    ListNode curr = head;
    ListNode prev = null;
    
    while (curr != null) {
      ListNode next = curr.next;
      if (prev != null) {
        prev.next = next;
      }
      prev = curr;
      curr = next;
    }
    
    prev.next = null;
    curr = head;
    
    while (curr.next != null) {
      curr = curr.next;
    }
    curr.next = evenHead;

    return head;
  }
}
__________________________________________________________________________________________________
sample 34636 kb submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if(head!=null) {
            ListNode odd = head;
            ListNode even = head.next;
            ListNode evenHead = even;
            while (even != null && even.next != null) {
                odd.next = odd.next.next;
                even.next = even.next.next;
                odd = odd.next;
                even = even.next;
            }
            odd.next=evenHead;
        }
        return head;
    }
}
__________________________________________________________________________________________________
