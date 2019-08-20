__________________________________________________________________________________________________
sample 60 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        def dfs(a,b):
            if not a or not b:
                return not a and not b
            if a.val==b.val and dfs(a.left,b.left) and dfs(a.right,b.right):
                return True
            if b is t:
                return dfs(a.left,t) or dfs(a.right,t)
            
            return dfs(a,t)
        
        return dfs(s,t)
__________________________________________________________________________________________________
sample 14252 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isMatch(self, s, t):
        if not(s and t):
            return s is t
        return (s.val == t.val and 
                self.isMatch(s.left, t.left) and 
                self.isMatch(s.right, t.right))

    def isSubtree(self, s, t):
        if self.isMatch(s, t): return True
        if not s: return False
        return self.isSubtree(s.left, t) or self.isSubtree(s.right, t)  
__________________________________________________________________________________________________
