__________________________________________________________________________________________________
sample 12 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        num = 0
        
        while head:
            num = 2 * num + head.val
            head = head.next
        
        return num
__________________________________________________________________________________________________
sample 16 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        output= 0
        while head:
            output = (output << 1) | head.val
            head = head.next
        return output
__________________________________________________________________________________________________
