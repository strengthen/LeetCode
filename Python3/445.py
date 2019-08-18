__________________________________________________________________________________________________
sample 64 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        l1_int = 0
        while l1:
            l1_int = l1_int * 10 + l1.val
            l1 = l1.next
        l2_int = 0
        while l2:
            l2_int = l2_int * 10 + l2.val
            l2 = l2.next
        summed_list = l1_int + l2_int
        if summed_list == 0:
            return ListNode(0)
        node_tmp = None
        while summed_list > 0:
            n = summed_list % 10
            new_node = ListNode(n)
            new_node.next = node_tmp
            node_tmp = new_node
            summed_list = summed_list // 10
        return node_tmp
__________________________________________________________________________________________________
sample 13064 kb submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        if l1 is None: return l2
        if l2 is None: return l1
        
        l1_vals, l2_vals = [], []

        def traverse(node, vals):
            while node:
                vals.append(node.val)
                node = node.next
    
        traverse(l1, l1_vals)
        traverse(l2, l2_vals)

        final_vals = l1_vals if len(l1_vals) > len(l2_vals) else l2_vals
        
        c = 0
        for i in range(len(final_vals)):
            if i <= min(len(l1_vals), len(l2_vals)) - 1:
                sums = l1_vals[len(l1_vals) - 1 - i] + l2_vals[len(l2_vals) - 1 - i] + c
            elif len(l1_vals) > len(l2_vals):
                sums = l1_vals[len(l1_vals) - 1 - i] + c
            elif len(l1_vals) < len(l2_vals):
                sums = l2_vals[len(l2_vals) - 1 - i] + c
                       
            if sums >= 10:
                sums, c = sums % 10, sums // 10
            else:
                c = 0

            final_vals[len(final_vals) - i - 1] = sums

        if c == 1: final_vals.insert(0, 1)
                       
        head = ListNode(final_vals[0])
        cur = head

        for i in range(1, len(final_vals)):
            node = ListNode(final_vals[i])
            cur.next = node
            cur = node
        
        return head
__________________________________________________________________________________________________
