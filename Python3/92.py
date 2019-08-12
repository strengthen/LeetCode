__________________________________________________________________________________________________
sample 20 ms submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        z=ListNode(-1)
        z.next=head
        l=z
        for i in range(m-1):
            l=l.next
        r=l.next
        for i in range(n-m):
            t=r.next
            r.next=t.next
            t.next=l.next
            l.next=t
        return z.next
__________________________________________________________________________________________________
sample 12968 kb submission
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        
        if head is None:
            return head
    
        if m > n:
            return head
        
        index = 1
        node = head        
        start_node = prev_node = None
        end_node = None
        nodes_2_rev=[]
        
        while node is not None:
            if index == m:
                start_node = prev_node
                            
            if (index >= m) and (index <= n):
                nodes_2_rev.append(node)
                
            prev_node = node
            node = node.next
            if index == n:
                end_node = node            
            
            index = index + 1
        
        k = n - m + 1
        
        if start_node is None:
            head = nodes_2_rev[k-1]
        else:
            start_node.next = nodes_2_rev[k-1]
                
        for i in range(k-1,0,-1):
            nodes_2_rev[i].next = nodes_2_rev[i-1]
        
        nodes_2_rev[0].next = end_node
        
        
        return head
__________________________________________________________________________________________________
