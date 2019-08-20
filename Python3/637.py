__________________________________________________________________________________________________
sample 44 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        if not root:
            return []
        res = []
        q = [root]
        while q:
            level_sum = 0
            level_count = 0
            next_level = []
            for node in q:
                level_sum += node.val
                level_count += 1
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            q = next_level
            res.append(level_sum/level_count)
        return res
__________________________________________________________________________________________________
sample 15420 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def averageOfLevels(self, root: TreeNode) -> List[float]:
        if not root:
            return []
        stack = [root]
        res = []
        while stack:
            current = []
            next_level = []
            for node in stack:
                current.append(node)
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            res.append(sum(i.val for i in current) / len(current))
            stack = next_level
        return res
__________________________________________________________________________________________________
