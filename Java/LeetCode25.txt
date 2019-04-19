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
  public ListNode reverseKGroup(ListNode head, int k) {
    if (head == null) return null;
    int count = 0;
    ListNode dummy = new ListNode(0);
    ListNode pre = dummy;
    dummy.next = head;
    while (head != null) {
      count++;
      if (count%k == 0) {
        pre = reverse(pre, head.next);
        head = pre.next;
      } else {
        head = head.next;
      }
    }
    return dummy.next;
  }
  private static ListNode reverse(ListNode head, ListNode last) {
    //   a linked list:
    //   0->1->2->3->4->5->6
    //   |           |
    //   pre        next
    ListNode newhead = head.next;
    ListNode cur = head.next;
    ListNode pre = last;
    while (cur != last) {
      ListNode next = cur.next;
      cur.next = pre;
      pre = cur;
      cur = next;
    }
    head.next = pre;
    return newhead;
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
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null || head.next == null || k<2)return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode tail=dummy, prev=dummy, temp;
        while(true){
            int count = k;
        while(count>0 && tail!=null){
            count--;
            tail=tail.next;
        }
        if(tail == null)break;
        
        head = prev.next;
        while(prev.next != tail){
            temp = prev.next;
            prev.next = temp.next;
            temp.next = tail.next;
            tail.next = temp;
        }
        
        tail = head;
            prev = head;
        }
        return dummy.next;
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
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null){
            return head;
        }
        Deque<ListNode> stack = new ArrayDeque<>();
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode current = dummy;
        ListNode next = dummy.next;
        while (next != null){
            for (int i = 0; i < k ; i++){
                if (next != null){
                    stack.offerFirst(next);
                    next = next.next;
                   } 
            }
            if (stack.size() != k) return dummy.next;
            while (stack.size() != 0){
                current.next = stack.pollFirst();
                current = current.next;
            }
            current.next = next;
        }
        return dummy.next;
        
    }
}
__________________________________________________________________________________________________
35312 kb
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || !hasMore(head, k)) return head;
        ListNode next = head;
        int count = k;
        while (k-- != 0) next = next.next;
        k=count;
        ListNode nroot = reverseTill(head, k);
        ListNode cur = nroot;
        k = count;
        while(k-- != 1) cur = cur.next;
        k = count;
        cur.next = reverseKGroup(next, k);
        return nroot;
    }
   

    private void print(ListNode head) {
        ListNode cur = head;
        while (cur != null) {
            System.out.print(cur.val + "->");
            cur = cur.next;
        }
        System.out.println();
    }
    private ListNode reverseTill(ListNode head, int k) {
        if (k == 0) return head;
        ListNode cur = head, prev = null;
        while (k != 0) {
            ListNode next = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next;
            k--;
        }
        return prev;
    }

    private boolean hasMore(ListNode head, int k) {
        if (head == null && k == 0) return true;
        if (head == null || k == 0) return false;
        ListNode cur = head;
        while (--k != 0) {
            cur = cur.next;
            if (cur == null) return k==0;
        }
        return true;
    }
}
__________________________________________________________________________________________________
35344 kb
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode root = new ListNode(0), tmp = root;
        root.next = head;
        while(makeSure(tmp, k)) {
            tmp = reverse(tmp, k);
        }
        
        return root.next;
    }
    
    private boolean makeSure(ListNode prev, int k) {
        while (k > 0 && prev.next != null) {
            k --;
            prev = prev.next;
        }
        
        return k == 0;
    }
    
    private ListNode reverse(ListNode prev, int k) {
        ListNode ret = prev.next, tmp = ret.next;
        while (k > 1) {
            ret.next = tmp.next;
            tmp.next = prev.next;
            prev.next = tmp;
            tmp = ret.next;
            k --;
        }
        
        return ret;
    }
}
__________________________________________________________________________________________________
