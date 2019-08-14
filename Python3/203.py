__________________________________________________________________________________________________
sample 52 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        
        cur = dummy
        
        while cur and cur.next:
            if cur.next.val == val:
                cur.next = cur.next.next
                continue
            cur = cur.next
        
        return dummy.next
__________________________________________________________________________________________________
sample 16280 kb submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        dummy = ListNode(1)
        dummy.next = head
        pre, cur = dummy, head
        while cur:
            flag = 1
            if cur.val == val:
                flag = 0
                pre.next = cur.next
            cur = cur.next
            if flag:
                pre = pre.next
        return dummy.next
__________________________________________________________________________________________________
