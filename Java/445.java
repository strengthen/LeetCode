__________________________________________________________________________________________________
sample 2 ms submission
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
        ListNode result = null;
        ListNode headDupList1 = null;
        ListNode headDupList2 = null;
        
        ListNode l1Next = l1;
        ListNode l2Next = l2;
        
        while (l1Next != null) {
            if (headDupList1 != null) {
                ListNode newHead = new ListNode(l1Next.val);
                newHead.next = headDupList1;
                headDupList1 = newHead;
                
            } else {
                headDupList1 = new ListNode(l1Next.val);
            }
            l1Next = l1Next.next;
        }
        
         while (l2Next != null) {
            if (headDupList2 != null) {
                ListNode newHead = new ListNode(l2Next.val);
                newHead.next = headDupList2;
                headDupList2 = newHead;
                
            } else {
                headDupList2 = new ListNode(l2Next.val);
            }
            l2Next = l2Next.next;
        }
        
        ListNode head1 = headDupList1;
        ListNode head2 = headDupList2;
        ListNode headResult = null;
        int carry = 0;
        while(head1 != null || head2 != null || carry != 0) {
            int sum = (head1 != null ? head1.val : 0) + (head2 != null ? head2.val : 0) + carry;
            int finalsum = sum % 10;
           
                if (carry != 0) {
                    carry=0;
                }
            carry = sum / 10;
            
            if (result != null) {
                ListNode previous = new ListNode(finalsum);
                previous.next = result;
                result = previous;
            } else {
                result = new ListNode(finalsum);
            }
            
            head1 = head1 != null ? head1.next : null;
            head2 = head2 != null ? head2.next : null;
        }
       return result; 
    }
}
__________________________________________________________________________________________________
sample 37624 kb submission
import java.util.HashMap;

/*
 * @lc app=leetcode id=445 lang=java
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (49.54%)
 * Total Accepted:    84.6K
 * Total Submissions: 170.7K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 * 
 * 
 * 
 * Example:
 * 
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 * 
 * 
 */
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
        List<Integer> list1 = new ArrayList();
        while (l1 != null) {
            list1.add(l1.val);
            l1 = l1.next;
        }

        List<Integer> list2 = new ArrayList();
        while (l2 != null) {
            list2.add(l2.val);
            l2 = l2.next;
        }

        List<Integer> result = new ArrayList<>();
        // 已读取的节点
        int readNodes = 0;
        // 是否产生进位
        boolean flag = false;
        while (readNodes < list1.size() && readNodes < list2.size()) {
            int tmp = list1.get(list1.size() - 1 - readNodes) + list2.get(list2.size() - 1 - readNodes);
            tmp += flag? 1: 0;
            flag = tmp > 9? true: false;
            result.add(tmp > 9? tmp - 10: tmp);
            readNodes++;
        }
        if (readNodes <= list1.size() - 1) {
            for (int i = list1.size() - 1 - readNodes; i >= 0; i--) {
                // 这里还可能存在进位 [9, 9] [1]
                int tmp = flag? list1.get(i) + 1: list1.get(i);
                flag = tmp > 9? true: false;
                result.add(tmp > 9? tmp - 10: tmp);
            }
        }
        if (readNodes <= list2.size() - 1) {
            for (int i = list2.size() - 1 - readNodes; i >= 0; i--) {
                int tmp = flag? list2.get(i) + 1: list2.get(i);
                flag = tmp > 9? true: false;
                result.add(tmp > 9? tmp - 10: tmp);
            }
        }
        // 可能两个链表一起读完，但是会有进位 比如[5], [5]
        if (flag) {
            result.add(1);
        }

        ListNode head = new ListNode(0);
        ListNode p = head;
        for (int i = result.size() - 1; i >= 0; i--) {
            ListNode node = new ListNode(result.get(i));
            p.next = node;
            p = node;
        }
        return head.next;
    }
}

__________________________________________________________________________________________________
