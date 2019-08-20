__________________________________________________________________________________________________
sample 616 ms submission
"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        #way1 recursive
        res = [] 
        def helper(node):
            if not node:
                return 
            for child in node.children:
                helper(child)
            res.append(node.val)
        helper(root)
        return res
__________________________________________________________________________________________________
sample 17552 kb submission
"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        
        
        res = []
        
        def check(x):
            nonlocal res
            if x:
                if not x.children:
                    res.append(x.val)
                else:
                    for child in x.children:
                        check(child)
                    res.append(x.val)
            
        if root:
            check(root)
            
        return res
__________________________________________________________________________________________________
