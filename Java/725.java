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
    public ListNode[] splitListToParts(ListNode root, int k) {
        ListNode curr = root;
        int n= 0;
        while(curr!=null){
            curr = curr.next;
            n++;
        }
        int width = n/k, rem = n%k;
        ListNode[] ans = new ListNode[k];
        curr = root;
        for(int i=0; i<k; i++){
            ListNode head = new ListNode(0), write = head;
            for(int j=0; j<width+(i<rem?1:0); j++){
                write = write.next = new ListNode(curr.val);
                if(curr!=null)
                curr = curr.next;
            }
            ans[i] = head.next;
        }
        return ans;
    }
}
__________________________________________________________________________________________________
sample 37072 kb submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode[] splitListToParts(ListNode root, int k) {
        int len = 0;
        for (ListNode cur = root; cur != null; cur = cur.next) len++;
        int base = len / k;
        int remainder = len % k;
        ListNode[] result = new ListNode[k];
        for (int i = 0; i < k; i++) {
            result[i] = root;
            if(root == null) continue;
            int step = remainder-- > 0 ? base + 1 : base;
            for (int j = 0; j < step - 1; j++) {
                root = root.next;
            }
            ListNode tmp = root.next;
            root.next = null;
            root = tmp;
        }
        return result;
    }
}
__________________________________________________________________________________________________
