__________________________________________________________________________________________________
0ms
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null) return l2;
		if(l2 == null) return l1;
		if(l1.val < l2.val){
			l1.next = mergeTwoLists(l1.next, l2);
			return l1;
		} else{
			l2.next = mergeTwoLists(l1, l2.next);
			return l2;
		}
    }
}
__________________________________________________________________________________________________
1ms
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        ListNode temp1 = new ListNode(0);
        ListNode result = new ListNode(0);
        ListNode head = new ListNode(0);
        int count = 0;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                temp1 = l1;
                l1 = l1.next;
            } else {
                temp1 = l2;
                l2 = l2.next;
            }
            if (count == 0) {
                head = temp1;
                
            }
            result.next = temp1;
            result = result.next;
            count++;
        }
        if (l1 == null) {
            result.next = l2;
        }
        if (l2 == null) {
            result.next = l1;
        }
        return head;
    }
}
__________________________________________________________________________________________________
2ms
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1==null && l2==null) return null;
        if(l1==null) return l2;
        if(l2==null) return l1;
        
        List<Integer> list = new ArrayList<>();
        ListNode curr = l1;
        while(curr!=null){
            list.add(curr.val);
            curr = curr.next;
        }
        
        curr = l2;
        
        while(curr!=null){
            list.add(curr.val);
            curr = curr.next;
        }
        
        Collections.sort(list);
        Iterator<Integer> it = list.iterator();
        
        ListNode head = new ListNode(it.next());
        curr = head;
        
        while(it.hasNext()){
            curr.next = new ListNode(it.next());
            curr = curr.next;
        }
        return head;
    }
}
__________________________________________________________________________________________________
35292 kb 
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null) return l2;
		if(l2 == null) return l1;
		if(l1.val < l2.val){
			l1.next = mergeTwoLists(l1.next, l2);
			return l1;
		} else{
			l2.next = mergeTwoLists(l1, l2.next);
			return l2;
		}
    }
}
__________________________________________________________________________________________________
35296 kb
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode dummyHead = dummy;
        while(l1 != null || l2 != null) {
            if(l1 != null && l2 == null || l1 != null && l2 != null && (l1.val <= l2.val)){
                dummy.next = l1;
                l1 = l1.next;
                dummy = dummy.next;
            }else {
                dummy.next = l2;
                l2 = l2.next;
                dummy = dummy.next;
            }
          
        }
        return dummyHead.next;
    }
}
__________________________________________________________________________________________________
