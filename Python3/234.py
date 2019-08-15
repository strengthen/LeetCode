__________________________________________________________________________________________________
sample 60 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head:
            return True
        slow = head
        fast = head
        stack = [slow.val]
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            stack.append(slow.val)
        stack.pop()
        if fast:
            slow = slow.next
        while slow:
            if slow.val != stack.pop():
                return False
            slow = slow.next
        return True
__________________________________________________________________________________________________
sample 23464 kb submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head:
            return True
        fast = slow = head
        while fast.next != None and fast.next.next != None:
            fast = fast.next.next
            slow = slow.next
        if fast != None:
            slow = slow.next
        half = self.reverse(slow)
        while half != None:
            if head.val != half.val:
                return False
            head = head.next
            half = half.next
        return True
__________________________________________________________________________________________________
