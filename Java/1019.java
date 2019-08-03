__________________________________________________________________________________________________
sample 3 ms submission
sample 3 ms submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int[] nextLargerNodes(ListNode head) {
        ListNode tmp = head;
        int length = 0;
        while (tmp != null) {
            length++;
            tmp = tmp.next;
        }
        
        int[] result = new int[length];
        int top = -1;
        int[] stack = new int[length];
        int[] position = new int[length];
        int cnt = 0;
        while (head != null) {
            if (top == -1) {
                stack[++top] = head.val;
                position[top] = cnt;
                head = head.next;
                cnt++;
            } else if(head.val <= stack[top]) {
                stack[++top] = head.val;
                position[top] = cnt;
                head = head.next;
                cnt++;
            } else {
                result[position[top]] = head.val;
                top--;
            }
        }
        return result;
    }
}
__________________________________________________________________________________________________
sample 38732 kb submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int[] nextLargerNodes(ListNode head) {
        
        List<Integer> ans = new ArrayList<>();
        ListNode slow = head;
        ListNode fast = slow.next;
        while(fast!=null){
             while(slow.val>=fast.val && fast.next!=null){
                fast=fast.next;
            }
            if(slow.val>=fast.val){
                ans.add(0);
            }
            else{
                ans.add(fast.val);
            }
            slow=slow.next;
            fast=slow.next;
        }
        if(slow!=null){
            ans.add(0);
        }
        return ans.stream().mapToInt(i -> i).toArray();
    }
}
__________________________________________________________________________________________________
