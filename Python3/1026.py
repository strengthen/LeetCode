__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def maxAncestorDiff(self, root):
        self.ans = 0
        def dfs(node, a, b):
            if node:
                a, b = min(a, node.val), max(b, node.val)
                self.ans = max(self.ans, b-a)
                dfs(node.left, a, b), dfs(node.right, a, b)
        dfs(root, float('inf'), float('-inf'))
        return self.ans
__________________________________________________________________________________________________
sample 14636 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        max_ancestor_diff = float("-inf")
        nodes = [(root, float("inf"), float("-inf"))]
        while nodes:
            node, lo, hi = nodes.pop()
            if not node:
                max_ancestor_diff = max(max_ancestor_diff, abs(hi - lo))
                continue
            lo, hi = min(lo, node.val), max(hi, node.val)
            nodes += [(node.right, lo, hi), (node.left, lo, hi)]
        return max_ancestor_diff
__________________________________________________________________________________________________
