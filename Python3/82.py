__________________________________________________________________________________________________
sample 28 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        anchor_node = ListNode(None)
        cur_node = anchor_node
        slow_search_node = head
        while slow_search_node:
            search_node = slow_search_node.next
            should_add = True
            while search_node and search_node.val == slow_search_node.val:
                search_node = search_node.next
                should_add = False
            
            if should_add:
                cur_node.next = ListNode(slow_search_node.val)
                cur_node = cur_node.next
            slow_search_node = search_node
        
        return anchor_node.next
__________________________________________________________________________________________________
sample 13028 kb submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        
        dummy = ListNode(0)
        dummy.next = head
        prenode, node = dummy, head
        while(node):
            if(node.next and node.val==node.next.val):
                while(node.next and node.val==node.next.val): node = node.next
                node = node.next
                prenode.next = node
            else:
                prenode.next = node
                prenode = node
                node = node.next
        
        return dummy.next
__________________________________________________________________________________________________
