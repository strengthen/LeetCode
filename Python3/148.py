__________________________________________________________________________________________________
sample 76 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        node = head
        ls = []
        
        while node:
            ls.append(node.val)
            node = node.next
            
        ls.sort()
        
        root = node = head
        
        for val in ls:
            node.val = val
            node = node.next
            
        return root
__________________________________________________________________________________________________
sample 20400 kb submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        #use the list to solve the problem        
        list=[]
        res=head
        while head:
            list.append(head.val)
            head=head.next
        
        list.sort()
        head=res
        #Following is important
        for part in list:
            res.val=part
            res=res.next
        return head
__________________________________________________________________________________________________
