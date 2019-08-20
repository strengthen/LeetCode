__________________________________________________________________________________________________
sample 24 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        self.ans = float('inf')
        cur = root.val
        def dfs(root):
            if not root: return "#"
            if cur < root.val < self.ans: self.ans= root.val
            #if not root.left or not root.right: return "#"
                        
            dfs(root.left)
            dfs(root.right)
        
        dfs(root)    
        if self.ans == cur or self.ans == float('inf'): return -1
        return self.ans
__________________________________________________________________________________________________
sample 13060 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        
        self.result = float('inf')
        min1 = root.val
        
        def dfs(node):
            if node:
                if min1 < node.val < self.result:
                    self.result = node.val
                elif node.val == min1:
                    dfs(node.left)
                    dfs(node.right)
        
        dfs(root)
        return self.result if self.result < float('inf') else -1
__________________________________________________________________________________________________
