__________________________________________________________________________________________________
sample 600 ms submission
"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        array = []
        
        stack = [root]
        while stack:
            node = stack.pop()
            if node:
                array.append(node.val)
                       
                stack += [node for node in node.children[::-1] if node]
                
        return array
__________________________________________________________________________________________________
sample 17516 kb submission
"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        self.newlist = [];
        if not root:
            return self.newlist
        self.newlist.append(root.val)
        def addnode(current: 'Node'):
            if current.children:
                for c in current.children:
                    self.newlist.append(c.val)
                    addnode(c)
        addnode(root)
        return self.newlist        
__________________________________________________________________________________________________
