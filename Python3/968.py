__________________________________________________________________________________________________
sample 40 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minCameraCover(self, root: TreeNode) -> int:
        
        self.returned = 0
        
        def dfs(self, node):
            if not node:
                return 1
            
            l = dfs(self, node.left)
            r = dfs(self, node.right)
            
            if not l or not r:
                self.returned += 1
                return 2
            
            if l == 2 or r == 2:
                return 1
            
            return 0
        
        if not dfs(self, root):
            self.returned += 1
        
        return self.returned
__________________________________________________________________________________________________
sample 44 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minCameraCover(self, root):
        self.res = 0

        def dfs(root):
            if not root:
                return 2
            l, r = dfs(root.left), dfs(root.right)
            if l == 0 or r == 0:
                self.res += 1
                return 1
            return 2 if l == 1 or r == 1 else 0

        return (dfs(root) == 0) + self.res
__________________________________________________________________________________________________
