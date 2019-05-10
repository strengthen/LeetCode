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
    public ListNode partition(ListNode head, int x) {
       if(head==null||head.next==null) return head;
       ListNode l1 = new ListNode(0);
       ListNode l2 = new ListNode(0);
       ListNode cur1 = l1;
       ListNode cur2 = l2;
       ListNode cur = head;
       while(cur!=null){
           if(cur.val<x){
               cur1.next = cur;
               cur1 = cur1.next;
           }
           else{
               cur2.next = cur;
               cur2 = cur2.next;
           }
           cur = cur.next;    
       }
       cur2.next = null;
       cur1.next = l2.next;
       return l1.next;
       
    }
}
__________________________________________________________________________________________________
sample 34200 kb submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
          if(head == null) return null;
        
        ListNode node = new ListNode(0);
        ListNode result = node;
        node.next = head;
        ListNode greatHead = new ListNode(0);
        ListNode greatTail = greatHead;
        while(node.next != null){
            
            if(node.next.val >= x){
                greatTail.next = node.next;
                greatTail = node.next;
                node.next = greatTail.next;
            }else{
                node = node.next;
            }
        }
        node.next = greatHead.next;
        greatTail.next = null;
        return result.next;
        
    }
}
__________________________________________________________________________________________________
