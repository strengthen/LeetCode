__________________________________________________________________________________________________
104ms
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        bool hasCarry = false;
        ListNode result = null;
        ListNode resultNextDigit = null;
        int nextDigit = 0;
        
        while ((l1 != null) || (l2 != null))
        {
            nextDigit = AddNumbersReturnCarry(GetVal(l1), GetVal(l2), ref hasCarry);
            if (result == null)
            {
               resultNextDigit = new ListNode(nextDigit);
               result =  resultNextDigit;               
            }
            else
            {
                resultNextDigit.next = new ListNode(nextDigit);
                resultNextDigit = resultNextDigit.next;
            }
            
            
            if (l1!= null) l1 = l1.next;
            if (l2!= null) l2 = l2.next;
        }
                                              
        if (hasCarry)
        {
            resultNextDigit.next =  new ListNode(1);
            resultNextDigit = resultNextDigit.next;
        }
                                              
        resultNextDigit.next = null;                                   
                                              
        return result;
        
    }
    
    public int AddNumbersReturnCarry(int first, int second, ref bool carry)
    {
        int val = first + second;
        if (carry) val = val + 1;
        
        if (val > 9)
        {
            carry = true;
            val = val - 10;            
        }
        else
        {
            carry = false;
        }       
        
        return val;
    }
    
    public int GetVal(ListNode l)
    {
        if (l == null)
            return 0;
        else
            return l.val;        
    }
}
__________________________________________________________________________________________________
108ms
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ans = new ListNode(0);
        ListNode a = l1, b = l2, current = ans;
        int carry = 0;
                            
        while (a != null || b != null)
        {
            int sum = (a != null ? a.val : 0) + (b != null ? b.val : 0) + carry;
            carry = sum / 10;
            
            current.next = new ListNode(sum % 10);         
            current = current.next;
            
            if (a != null)
                a = a.next;
            if (b != null)
                b = b.next;
        }
        
        if (carry > 0)
            current.next = new ListNode(carry);
        
        return ans.next;
    }
}
__________________________________________________________________________________________________
112ms
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    private ListNode head = new ListNode(-1);    
    private ListNode tail = null;
    private bool carry = false;
    
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        tail = head;
        var cn1 = l1;
        var cn2 = l2;
        
        while (cn1 != null || cn2 != null)
        {
            var val1 = 0;
            var val2 = 0;
            if(cn1 != null)
            {
                val1 = cn1.val;
                cn1 = cn1.next;
            }
            if(cn2 != null)
            {
                val2 = cn2.val;
                cn2 = cn2.next;
            }
            var total = val1 + val2;
            AddNodes(total);
        }
        if(carry)
        {
            AddNode(1);
            carry = false;
        }
        return head;
    }
    
    private void AddNodes(int total)
    {
        if(carry)
        {
            total++;
        }
        if(tail.val == -1)
        {
            tail.val = total;    
        }
        else
        {
            AddNode(total);
        }
        if(tail.val >= 10)
        {
            tail.val -= 10;
            carry = true;
        }
        else
        {
            carry = false;
        }
    }
    
    private void AddNode(int val)
    {
        var node = new ListNode(val);
        tail.next = node;
        tail = tail.next;
    }
}
__________________________________________________________________________________________________
116ms
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    
    /// A queue based implementation
    /// Keep two queues each of first and second list.
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        var q1 = new Queue<ListNode>();
        var q2 = new Queue<ListNode>();
        
        while(l1 != null){
            q1.Enqueue(l1);
            l1 = l1.next;
        }
        
        while(l2 !=null){
            q2.Enqueue(l2);
            l2 = l2.next;
        }
        
        ListNode result =null; 
        int carry = 0;
        var r = new Queue<int>();
        while(q1.Count > 0 && q2.Count > 0){
            var f = q1.Dequeue();
            var s = q2.Dequeue();
            var t = f.val + s.val + carry;
            //Console.WriteLine($"{t}={f.val}+{s.val}+{carry}");
            carry = (int) t/10;
            var el = (int) t%10;
            r.Enqueue(el);
        }        
        
        while(q1.Count > 0){
            var f = q1.Dequeue();
            var t = f.val + carry;
            carry = (int) t/10;
            var el = (int) t%10;
            r.Enqueue(el);
            
            
        }
        
         while(q2.Count > 0){
            var f = q2.Dequeue();
            var t = f.val + carry;
            carry = (int) t/10;
            var el = (int) t%10;
            r.Enqueue(el);
        }
        
        if(carry >0 ){
             r.Enqueue(carry);
        }
        
        result = new ListNode(r.Dequeue());
        var next = result;
        while(r.Count > 0){
            next.next = new ListNode(r.Dequeue());
            next = next.next;            
        }        
        return result;
    }
}
__________________________________________________________________________________________________
25068 kb
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        if(l1 == null)return l2;
        if(l2== null)return l1;
        ListNode head = null;
        ListNode curr = null;
        
        int carry = 0;
        while(l1 !=null || l2 != null || carry != 0)
        {
            int a = l1 != null ? l1.val : 0;
            int b = l2 != null ? l2.val : 0;
           int sum = a + b + carry;
           carry = sum/10;
           ListNode node = new ListNode(sum%10);
           if(head == null) 
           {
               head = node;
               curr = head;
           }
            else
            {
                curr.next = node;
                curr = curr.next; 
            }
            if(l1 != null)
                l1 = l1.next;
            if(l2 != null)
                l2 = l2.next;
        }
        return head; 
    }
}
__________________________________________________________________________________________________
