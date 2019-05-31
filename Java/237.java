__________________________________________________________________________________________________
sample 34404 kb submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        //相当于把节点的下一个节点赋值给这个节点，然后把下个节点删掉
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
__________________________________________________________________________________________________
sample 36116 kb submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
        System.gc();
    }
}
__________________________________________________________________________________________________
