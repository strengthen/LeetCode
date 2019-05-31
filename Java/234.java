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
    public boolean isPalindrome(ListNode head) {
        int count=0;
        ListNode it=head;
        while(it!=null){count++;it=it.next;}
        int[] vals=new int[count/2];
        it=head;
        for(int i=0;i<vals.length;i++){
            vals[i]=it.val;
            it=it.next;
        }
        if(vals.length>0 && count%2>0)it=it.next;
        for(int i=vals.length-1;i>=0;i--){
            if(vals[i]!=it.val) return false;
            it=it.next;
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 38440 kb submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        // Reverse the linked list and verify
        ListNode fast = head;
        ListNode slow = head;
        Stack<Integer> stack = new Stack<Integer>();
        
        // Push elements from first half of linked list onto stack. When fast
        // runner reaches the end of the linked list, then we know we're at the 
        // middle
        while (fast != null && fast.next != null) {
            stack.push(slow.val);
            slow = slow.next;
            fast = fast.next.next;
        }
        if (fast != null) {
            slow = slow.next;
        }
        
        while (slow != null) {
            int top = stack.pop().intValue();
            if (top != slow.val) {
                return false;
            }
            slow = slow.next;
        }
        return true;
    }
}
__________________________________________________________________________________________________
