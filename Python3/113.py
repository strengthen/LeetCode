sample 36 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        results = []
        def dfs(node, s, stack):
            if node is None:
                return
            stack.append(node.val)
            if node.left is None and node.right is None:
                if s == node.val:
                    results.append(stack.copy())
            if node.left:
                dfs(node.left, s - node.val, stack)
            if node.right:
                dfs(node.right, s - node.val, stack)
            stack.pop()
        dfs(root, sum, [])
        return results            
__________________________________________________________________________________________________
sample 14240 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if not root:
            return []
        stack = [([root.val], sum - root.val, root)]
        res = []
        while stack:            
            trace, diff, node = stack.pop()
            if not node.left and not node.right and diff == 0:
                res.append(trace)
            if node.left:
                stack.append((trace + [node.left.val], diff - node.left.val, node.left))
            if node.right:
                stack.append((trace + [node.right.val], diff - node.right.val, node.right))
        return res
__________________________________________________________________________________________________
