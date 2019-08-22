__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def flipEquiv(self, root1: TreeNode, root2: TreeNode) -> bool:
        if not root1 and not root2:
            return True
        
        if not root1 or not root2:
            return False
        
        if root1.val != root2.val:
            return False
        
        return (self.flipEquiv(root1.left, root2.left) and self.flipEquiv(root1.right, root2.right) or self.flipEquiv(root1.left, root2.right) and self.flipEquiv(root1.right, root2.left))
__________________________________________________________________________________________________
sample 12964 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flipEquiv(self, root1: TreeNode, root2: TreeNode) -> bool:
        if not root1 and not root2:
            return True
        if not root1 or not root2:
            return False
        
        def dfs(r1, r2):
            if r1 is r2:
                return True
            if not r1 or not r2:
                return False
            if r1.val != r2.val:
                return False
            l = dfs(r1.left, r2.right)
            r = dfs(r1.right, r2.left)
            l1 = dfs(r1.left, r2.left)
            r1 = dfs(r1.right, r2.right)
            
            return l and r or l1 and r1
        
        return dfs(root1, root2)
__________________________________________________________________________________________________
