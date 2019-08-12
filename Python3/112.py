__________________________________________________________________________________________________
sample 32 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        
        curSum = 0
        return self.traverse(root, sum, curSum)
    
    def traverse(self, root, sum, curSum):
        if not root:
            return False
        
        curSum += root.val
        if not root.left and not root.right:
            return sum == curSum
        
        return self.traverse(root.left, sum, curSum) or self.traverse(root.right, sum, curSum)
__________________________________________________________________________________________________
sample 14956 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        stack = [(root.val,root),]
        while stack:
            s, root = stack.pop()
            if not root.left and not root.right and s == sum:
                return True
            children = [root.left, root.right]
            for c in children:
                if c:
                    stack.append((s + c.val, c))
        return False
__________________________________________________________________________________________________
