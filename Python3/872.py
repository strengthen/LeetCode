__________________________________________________________________________________________________
sample 24 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque

class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:  
        def get_leafs(root):
            if not root:
                return []
            if not root.left and not root.right:
                return [root.val]
            
            return get_leafs(root.left) + get_leafs(root.right)
        
        return get_leafs(root1) == get_leafs(root2)
__________________________________________________________________________________________________
sample 12908 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
                
        return self.getleaf(root1) == self.getleaf(root2)
        
        
    def getleaf(self, root):
        
        if not root: return []
        
        stack = [root]
        out = []
        while root.left:
            stack.append(root.left)
            root = root.left
            
        while stack:
            p = stack.pop()
            if not p.left and not p.right:
                out.append(p.val)
            
            if p.right:
                stack.append(p.right)
                p = p.right
                while p.left:
                    stack.append(p.left)
                    p = p.left
                    
        return out
__________________________________________________________________________________________________
