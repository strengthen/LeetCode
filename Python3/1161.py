__________________________________________________________________________________________________
Runtime: 388 ms
Memory Usage: 18.5 MB
class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        mapping = {}
        self.helper(mapping, root, 1)
        max_val, max_level = -9999999, 0
        for level, val in mapping.items():
            if val > max_val:
                max_val = val
                max_level = level
        return max_level

    def helper(self, mapping, root, level):
        if not root:
            return
        mapping[level] = mapping.get(level, 0) + root.val
        self.helper(mapping, root.left, level + 1)
        self.helper(mapping, root.right, level + 1)
__________________________________________________________________________________________________

__________________________________________________________________________________________________
