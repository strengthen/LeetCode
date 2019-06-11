# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sunm: int) -> List[List[int]]:
        a = []
        if not root:
            return []
        def dfs(root, al):
            if root.right:
                dfs(root.right, al+[root.right.val])
            if root.left:
                dfs(root.left, al+[root.left.val])
            if not root.right and not root.left:
                if sum(al) == sunm:
                    a.append(al)
        dfs(root, [root.val])
        return a
