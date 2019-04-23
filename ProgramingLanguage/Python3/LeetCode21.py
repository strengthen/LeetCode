__________________________________________________________________________________________________
40ms
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode(-1)
        cur = head
        while l1 != None and l2 != None:
            if l1.val < l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next
        if l1 == None:
            cur.next = l2
        if l2 == None:
            cur.next = l1
        return head.next
__________________________________________________________________________________________________
44ms
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is None:
            return l2
        elif l2 is None:
            return l1
        
        if l1.val <= l2.val:
            head = l1
            l1 = l1.next
        else:
            head = l2
            l2 = l2.next
            head.next = l1
        
        prio = head
            
        while l1 is not None and l2 is not None:
            if l1.val <= l2.val:
                l1 = l1.next
                prio = prio.next
            else:
                prio.next = l2
                prio = prio.next
                l2 = l2.next
                prio.next = l1
                
        if l1 is None:
            prio.next = l2
        
        del prio
        
        return head
__________________________________________________________________________________________________
48ms
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1 and not l2:
            return None

        if not l1:
            return l2

        if not l2:
            return l1

        if l1.val <= l2.val:
            first_node = ListNode(l1.val)
            l1 = l1.next
        else:
            first_node = ListNode(l2.val)
            l2 = l2.next

        cur_node = first_node
        while l1 and l2:
            if l1.val <= l2.val:
                cur_node.next = ListNode(l1.val)
                cur_node = cur_node.next
                l1 = l1.next
            else:
                cur_node.next = ListNode(l2.val)
                cur_node = cur_node.next
                l2 = l2.next

        while l1:
            print(l1.val)
            cur_node.next = ListNode(l1.val)
            cur_node = cur_node.next
            l1 = l1.next

        while l2:
            print(l2.val)
            cur_node.next = ListNode(l2.val)
            cur_node = cur_node.next
            l2 = l2.next

        return first_node
__________________________________________________________________________________________________
12144 kb
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: 'ListNode', l2: 'ListNode') -> 'ListNode':
        l_ret = None
        n = l_ret
        
        while l1 or l2:
            if not l2 or (l1 is not None and l1.val <= l2.val):
                val = l1.val
                l1 = l1.next
            else:
                val = l2.val
                l2 = l2.next
            
            if l_ret is None:
                l_ret = ListNode(val)
                n = l_ret
            else:
                n.next = ListNode(val)
                n = n.next
        
        return l_ret
__________________________________________________________________________________________________
12172 kb
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: 'ListNode', l2: 'ListNode') -> 'ListNode':
        if not l1:
            return l2
        if not l2:
            return l1
        
        if l1.val <= l2.val:
            head = l1
            l1 = l1.next
        else:
            head = l2
            l2 = l2.next
            
        head_copy = head
            
        while l1 or l2:
            if not l1:
                head.next = l2
                return head_copy
            if not l2:
                head.next = l1
                return head_copy
            
            if l1.val <= l2.val:
                head.next = l1
                head = head.next
                l1 = l1.next
            else:
                head.next = l2
                head = head.next
                l2 = l2.next            
__________________________________________________________________________________________________
