# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxAncestorDiff(self, root, mx=0, mn=10000):
        return max(mx - root.val, root.val - mn, \
            self.maxAncestorDiff(root.left, max(mx, root.val), min(mn, root.val)), \
            self.maxAncestorDiff(root.right, max(mx, root.val), min(mn, root.val))) \
            if root else 0
        