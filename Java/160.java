__________________________________________________________________________________________________
sample 0 ms submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
   public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode cur = headA;
        int lenA = 0;
        while(cur != null){
            lenA ++;
            cur = cur.next;
        }

        cur = headB;
        int lenB = 0;
        while(cur != null){
            lenB ++;
            cur = cur.next;
        }
        ListNode curA = headA;
        ListNode curB = headB;
        if(lenA > lenB) {
            for(int i=0; i<lenA-lenB; i++){
                curA = curA.next;
            }
        }
        if(lenA < lenB)  {
            for(int i=0; i<lenB-lenA; i++){
                curB = curB.next;
            }
        }
        while(curA!=null){
            if(curA == curB) return curA;
            curA = curA.next;
            curB = curB.next;
        }
        return null;
        
    }
}
__________________________________________________________________________________________________
sample 33492 kb submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    private int getLength(ListNode l){
            int length = 0;
            while(l!=null){
                l = l.next;
                length++;
            }
            return length;
        }
    
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {

        //先把长的一次一次截掉，到同一起点位置再一起走看能不能相遇
        
        if(headA==null || headB==null){
            return null;
        }
        
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        
        while(lenA > lenB){
            headA = headA.next;
            lenA--;
        }
        while(lenA < lenB){
            headB = headB.next;
            lenB--;
        }
        while(headA != headB){
            headA = headA.next;
            headB = headB.next;
        }
        
        return headA;
    }
}
__________________________________________________________________________________________________
