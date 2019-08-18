__________________________________________________________________________________________________
sample 844 ms submission
"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""
class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        
        def dfs(start):
            end = start.next
            node = start.child
            start.child = None
            start.next = node
            node.prev = start
            while node.next:
                if node.child:
                    dfs(node)
                node = node.next
            if end:
                node.next = end
                end.prev = node
            
        headSave = head
        
        while head:
            if head.child:
                dfs(head)
            head = head.next
            
        return headSave
__________________________________________________________________________________________________
sample 15648 kb submission
"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""
class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        
        def recurse(n):
            if not n:
                return n, n
            head, tail = n, n
            p = head
            while p:
                chead, ctail = recurse(p.child)
                p.child = None
                if chead:
                    chead.prev, ctail.next = p, p.next 
                    if p.next:
                        p.next.prev = ctail
                    p.next = chead
                    p = ctail
                tail = p
                p = p.next
            return head, tail 
        
        head, _ = recurse(head)
        return head
__________________________________________________________________________________________________
