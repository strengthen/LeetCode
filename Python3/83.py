__________________________________________________________________________________________________
sample 32 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        node = head
        while node and node.next:
            if node.val == node.next.val:
                node.next = node.next.next
            else:
                node = node.next
        return head
__________________________________________________________________________________________________
sample 13068 kb submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    """
           *     *
    Input: 1->1->2
    Output: 1->2
    """
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        # create dummy node
        dummy = ListNode(0)
        dummy.next = head
        current = dummy.next
        
        # loop while current is valid
        while current:
        
            # create a variable called skip
            skip = current.next
            
            # loop while skip.val == current.val
            while skip and skip.val == current.val:
                skip = skip.next
            
            # update current.next to be skip
            current.next = skip
            current = skip
            
        return dummy.next
__________________________________________________________________________________________________
