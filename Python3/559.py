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
    def maxDepth(self, root: 'Node') -> int:

        def dfs(root):
            if not root: return 0
            if not root.children: return 1
            height = list()
            for node in root.children:
                height.append(dfs(node))
            return max(height) + 1
        
        d = dfs(root)
        
        return d
__________________________________________________________________________________________________
sample 17320 kb submission
"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        global ans
        ans=0
        n=1
        if not root:
            return ans
        def f(a,n):
            global ans
            if a.children==[]:
                ans=max(ans,n)
                return
            for i in a.children:
                f(i,n+1)
        f(root,n)
        return ans
__________________________________________________________________________________________________
