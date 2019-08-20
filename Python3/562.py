__________________________________________________________________________________________________
sample 52 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findTilt(self, root: TreeNode) -> int:
        def goDeep(root):
            if not root: return 0, 0
            left, lsum = goDeep(root.left)
            right, rsum = goDeep(root.right)
            tilt = abs(lsum - rsum)
            return tilt+left+right, root.val+lsum+rsum
        return goDeep(root)[0]
__________________________________________________________________________________________________
sample 15420 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    tilt = 0
    def findTilt(self, root: TreeNode) -> int:
        self.sum(root)
        return self.tilt
    
    def sum(self, root: TreeNode) -> int:
        if root is None:
            return 0
        
        left = self.sum(root.left)
        right = self.sum(root.right)
        
        self.tilt += abs(left - right)
        return root.val + left + right
__________________________________________________________________________________________________
