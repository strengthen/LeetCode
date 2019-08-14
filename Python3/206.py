__________________________________________________________________________________________________
sample 20 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        curr = head
        new_head = None
        
        while curr:
            next_node = curr.next
            curr.next = new_head
            new_head = curr
            curr = next_node
        
        return new_head
__________________________________________________________________________________________________
sample 14236 kb submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None: return None
        pre, cur, nxt = None, head, head.next
        
        while cur:
            cur.next = pre
            pre = cur
            cur = nxt
            if cur: nxt = cur.next
        return pre
__________________________________________________________________________________________________
