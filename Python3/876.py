__________________________________________________________________________________________________
sample 20 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        if(head.next == None):
            return head
        slowPtr = head
        fastPtr = head.next
        while(fastPtr.next!=None and fastPtr.next.next!=None):
            fastPtr = fastPtr.next.next
            slowPtr = slowPtr.next
        return slowPtr.next
__________________________________________________________________________________________________
sample 13056 kb submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
import math

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        target = None
        length = Solution.getLength(head)
                
        if length % 2 == 0:
            target = (length/2) + 1
        else:
            target = math.ceil(length/2)
        
        n = 1
        node = head
        while True:
            if n == target:
                return node
            node = node.next
            n += 1
        
    @staticmethod
    def getLength(head: ListNode) -> int:
        n = 1
        node = head
        while node.next is not None:
            node = node.next
            n += 1
        return n
__________________________________________________________________________________________________
