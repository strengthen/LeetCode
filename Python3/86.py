__________________________________________________________________________________________________
ample 24 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        head1 = head2 = None
        cur1 = cur2 = None
        while head:
            if head.val < x:
                if head1:
                    cur1.next = head
                    cur1 = head
                else:
                    head1 = cur1 = head
            else:
                if head2:
                    cur2.next = head
                    cur2 = head
                else:
                    head2 = cur2 = head
            head = head.next            
        if cur1:
            cur1.next = head2            
        if cur2:
            cur2.next = None
        if cur1:
            return head1
        else:
            return head2        
__________________________________________________________________________________________________
sample 12900 kb submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        prev1 = l1dummy = ListNode('dummy1')
        prev2 = l2dummy = ListNode('dummy2')
        
        c = head
        while c:
            t = c.next
            c.next = None
            if c.val < x:
                prev1.next = c
                prev1 = prev1.next
                c = t
            else:
                prev2.next = c
                prev2 = prev2.next
                c = t
        prev1.next = l2dummy.next
        return l1dummy.next
__________________________________________________________________________________________________
