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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1);
        
        ListNode head = dummy;
        
        int r=0;
        while(l1 != null && l2 != null) {
            int cnt = l1.val + l2.val + r;
            ListNode node = new ListNode(cnt%10);
            r = cnt/10;
            head.next = node;
            head = head.next;
            l1 = l1.next;
            l2 = l2.next;
        }
        
        while(l1 != null) {
            int cnt = l1.val + r;
            ListNode node = new ListNode(cnt%10);
            r = cnt/10;
            head.next = node;
            head = head.next;
            l1 = l1.next;
        }
        
        while(l2 != null) {
            int cnt = l2.val + r;
            ListNode node = new ListNode(cnt%10);
            r = cnt/10;
            head.next = node;
            head = head.next;
            l2 = l2.next;
        }
        
        if(r != 0) {
            ListNode node = new ListNode(r);
            head.next = node;
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
      boolean carry = false;
        ListNode result = new ListNode(0);
        ListNode p = result;
        while(l1 != null || l2 != null){
        	int s = 0;
        	if(carry == true) {
        		s = 1;
        		carry = false;
        	}
            int a = l1 == null ? 0 : l1.val;
            int b = l2 == null ? 0 : l2.val;
            s += a + b;
            if(s >= 10) {
            	carry = true;
            	s %= 10;
            }
            p.next = new ListNode(s);
            p = p.next;
            if(l1 !=null)
            	l1 = l1.next;
            if(l2 !=null)
            	l2 = l2.next;
        }
        if(carry) {
        	p.next = new ListNode(1);
        }
        return result.next;
  
    }
}
__________________________________________________________________________________________________
3ms
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        List<Integer> tempNums = new ArrayList<>();
        boolean shift = false;
        do {
            int sum = addUp(l1, l2);
            if (shift) {
                sum += 1;
                shift = false;
            }
            if (sum < 10) {
                tempNums.add(sum);
            } else {
                shift = true;
                tempNums.add(sum - 10);
            }
            if (l1 != null) {
                l1 = l1.next;
            }
            if (l2 != null) {
                l2 = l2.next;
            }
        } while (l1 != null || l2 != null || shift);
        ListNode pre = null;
        for (int i = tempNums.size()-1; i >= 0; i--) {
            ListNode temp = new ListNode(tempNums.get(i));
            temp.next = pre;
            pre = temp;
        }
        return pre;
    }    
    
    private int addUp(ListNode l1, ListNode l2) {
        int result = 0;
        if (l1 != null) {
            result += l1.val;
        }
        if (l2 != null) {
            result += l2.val;
        }
        return result;
    }    
}
__________________________________________________________________________________________________
18ms
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
import java.math.BigInteger;
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        StringBuffer sb1 = new StringBuffer();
        while (l1!=null) {
            sb1.append(l1.val);
            l1 = l1.next;
        }
        StringBuffer sb2 = new StringBuffer();
        while (l2!=null) {
            sb2.append(l2.val);
            l2 = l2.next;
        }
        BigInteger a = new BigInteger(sb1.reverse().toString());
        BigInteger b = new BigInteger(sb2.reverse().toString());

        String result = a.add(b).toString();
        System.out.println(result);
        ListNode temp = new ListNode(Integer.valueOf(String.valueOf(result.charAt(result.length() - 1))));
        ListNode head = temp;
        for(int i=result.length()-2;i>=0;i--){
            temp.next = new ListNode(Integer.valueOf(String.valueOf(result.charAt(i))));
            temp = temp.next;

        }
        return head;
    }
}
__________________________________________________________________________________________________
36440 kb
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0; int sum = 0;
        ListNode start = new ListNode(0);
        ListNode head = start;
        start.next = head;
        
        while(l1 != null || l2 !=null){
            if(l1 == null){
                sum = 0 + l2.val + carry;
                carry = 0;
                if(sum >= 10){
                    carry = 1;
                    sum = sum%10;   
                }
                l2 = l2.next;
            }
            else if(l2 == null){
                sum = l1.val + 0 + carry;
                carry = 0;
                if(sum >= 10){
                    carry = 1;
                    sum = sum%10;
                }
                l1 = l1.next;
            }
            else{
                sum = l1.val + l2.val+carry;
                carry = 0;
                if(sum >= 10){
                    carry = 1;
                    sum = sum%10;
                }
                l1 = l1.next;
                l2 = l2.next;
            }
            head.next = new ListNode(sum);
            head = head.next;
            
        }
        if(carry == 1){
            head.next = new ListNode(carry);
        }
        return start.next;
        
    }
}
__________________________________________________________________________________________________
