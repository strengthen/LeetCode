__________________________________________________________________________________________________
sample 72 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        pre = []
        queue = [root]
        while queue:
            pre, queue = queue, [leaf for q in queue for leaf in [q.left, q.right] if leaf]
        return sum([p.val for p in pre])
__________________________________________________________________________________________________
sample 76 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        layer = [root]
        res = root.val
        while layer:
            next_layer = []
            next_res = 0
            for node in layer:
                next_res += node.val
                if node.left:
                    next_layer.append(node.left)
                if node.right:
                    next_layer.append(node.right)
            layer = next_layer
            res = next_res
        return res
__________________________________________________________________________________________________
