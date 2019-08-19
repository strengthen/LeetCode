__________________________________________________________________________________________________
sample 36 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        queue,ans = [root],0
        while queue:
            ans=queue[0].val
            queue=[leaf for node in queue for leaf in (node.left,node.right) if leaf]
        return ans
__________________________________________________________________________________________________
sample 15616 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        
        from collections import deque
        
        if not root:
            return -1
        
        dq = deque()
        dq.append((root, 0))
        
        curr_dep = 0
        ans = root.val
        
        while dq:
            node, dep = dq.popleft() 
            
            if dep > curr_dep:
                ans = node.val
                curr_dep = dep
                
            if node.left:
                dq.append((node.left, dep + 1))
                
            if node.right:
                dq.append((node.right, dep + 1))
                
        return ans        
__________________________________________________________________________________________________
