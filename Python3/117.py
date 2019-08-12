__________________________________________________________________________________________________
sample 364 ms submission
"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return root
        stack = [(root, 0)]     
        
        wait_node_dict = dict()
        while stack:
            node, level = stack.pop()
            if node is None:
                continue
            if level not in wait_node_dict:
                wait_node_dict[level] = node
            else:
                wait_node_dict[level].next = node
                wait_node_dict[level] = node
            stack.append((node.right, level + 1))
            stack.append((node.left, level + 1))
        
        return root 

__________________________________________________________________________________________________
sample 22432 kb submission
"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def find_next(self, parents):
        if not parents: return
        last = None
        for p in parents:
            if last: last.next = p
            last = p    
        children = [n for p in parents for n in [p.left, p.right] if n]    
        self.find_next(children)
        
        
    def connect(self, root: 'Node') -> 'Node':
        if not root: return None
        self.find_next([root])
        return root
__________________________________________________________________________________________________
