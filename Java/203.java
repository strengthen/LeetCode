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
    public ListNode removeElements(ListNode head, int val) {
        
        if(head == null){
            return null;
        }
        while(head != null && head.val == val){
            head = head.next;
        }
        if(head == null){
            return null;
        }
        ListNode ans = head;
        ListNode pre = head;
        head = head.next;
        while(head != null){
            if(head.val == val){
                while(head != null){
                    if(head.val != val){
                        break;
                    }
                    head = head.next;
                }
                if(head == null){
                    pre.next = null;
                    break;
                }
                pre.next = head;
                pre = head;
                head = head.next;
            }else{
                pre = head;
                head = head.next;
            }
        }
        return ans;
    }
}
__________________________________________________________________________________________________
sample 36472 kb submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution 
{
    public ListNode removeElements(ListNode head, int val) 
    {
        ListNode a = null;
        ListNode b = head;
        for(;b != null ;)
        {
            if(b.val != val) 
            {
                if(a == null)
                {
                    head = b;
                }
                a = b;
                b = b.next;
                
            }
            else
            {
                b = b.next;
                if(a != null && b != null && b.val != val)
                {
                    a.next = b;
                }
            }
                
        }
        System.gc();
        if (a == null)
        {
            return null;
        }
        else
        {
            a.next = b;
            return head;
        }
    }
}
__________________________________________________________________________________________________
