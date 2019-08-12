__________________________________________________________________________________________________
sample 32 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        
        def helper(node, level):
            if not node:
                return level
            
            return max(helper(node.left, level+1), helper(node.right, level+1))
        
        depth = helper(root, 0)
        return depth
__________________________________________________________________________________________________
sample 14288 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        d=1
        queue=[(d,root)]
        while queue:
            d,node=queue.pop(0)
            if node:
                queue.append((d+1,node.left))
                queue.append((d+1,node.right))
                
        return d-1
__________________________________________________________________________________________________
