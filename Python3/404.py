__________________________________________________________________________________________________
sample 20 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumOfLeftLeaves(self, root):
        self.sum = 0
        def dfs(node):
            if not node:
                return
            if node.left:
                if not node.left.left and not node.left.right:
                    self.sum += node.left.val
                else:
                    dfs(node.left)
            if node.right:
                dfs(node.right)
            return 
        dfs(root)
        return self.sum
__________________________________________________________________________________________________
sample 13296 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        if not root:
            return 0
        ans = 0
        stack = [(root,False)]
        while stack:
            cur, side = stack.pop()
            if not cur.left and not cur.right and side:
                ans += cur.val
                continue
            if cur.left:
                stack.append((cur.left,True))
            if cur.right:
                stack.append((cur.right,False))
        return ans
__________________________________________________________________________________________________
