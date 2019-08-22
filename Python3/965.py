__________________________________________________________________________________________________
sample 20 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque

class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        if not root:
            return False
        
        value = root.val
        q = deque([root])
        
        while len(q):
            node = q.popleft()
            
            if not node:
                continue
            if node.val != value:
                return False
            
            q.append(node.left)
            q.append(node.right)
        
        return True
__________________________________________________________________________________________________
sample 12988 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        self.value = root.val
        self.isunival = True
        def checkvalue(node: TreeNode):
            if node:
                if node.val != self.value:
                    self.isunival = False
                else:
                    checkvalue(node.left)
                    checkvalue(node.right)
        checkvalue(root)
        return self.isunival
__________________________________________________________________________________________________
