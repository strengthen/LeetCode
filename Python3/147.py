__________________________________________________________________________________________________
sample 48 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        node_vec = []
        while head:
            node_vec.append(head.val)
            head = head.next
        node_vec = sorted(node_vec)
        curr = new_node = ListNode(0)
        for i in range(len(node_vec)):
            curr.next = ListNode(node_vec[i])
            curr = curr.next
        return new_node.next
__________________________________________________________________________________________________
sample 14796 kb submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        sentinel = ListNode(-1)
        prev = sentinel
        
        while head:
            nxt = head.next
            
            if prev.val >= head.val:
                prev = sentinel
            
            while prev.next and prev.next.val < head.val:
                prev = prev.next
            
            head.next = prev.next
            prev.next = head
            head = nxt
            
        return sentinel.next
__________________________________________________________________________________________________
