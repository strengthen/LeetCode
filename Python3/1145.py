__________________________________________________________________________________________________
sample 36 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    node_x = None

    def btreeGameWinningMove(self, root: TreeNode, n: int, x: int) -> int:

        def count_nodes_above_x(node, x):
            if node.val == x:
                self.node_x = node
                return 0
            count = 1
            if node.left:
                count += count_nodes_above_x(node.left, x)
            if node.right:
                count += count_nodes_above_x(node.right, x)
            return count

        def count_nodes(node):
            count = 1
            if node.left:
                count += count_nodes(node.left)
            if node.right:
                count += count_nodes(node.right)
            return count

        parts = []
        parts.append(count_nodes_above_x(root, x))
        if self.node_x.left:
            parts.append(count_nodes(self.node_x.left))
        if self.node_x.right:
            parts.append(count_nodes(self.node_x.right))

        max_blue_node_count = max(parts)
        return max_blue_node_count * 2 > n
__________________________________________________________________________________________________
sample 40 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def btreeGameWinningMove(self, root: TreeNode, n: int, x: int) -> bool:
        left_x, right_x = 0, 0
        def dfs(t):
            if not t:
                return 0
            left, right = dfs(t.left), dfs(t.right)
            if t.val == x:
                self.left_x, self.right_x = left, right
            return left + right + 1
        dfs(root)
        return max([self.left_x, self.right_x, n - 1 - self.left_x - self.right_x]) > n / 2
__________________________________________________________________________________________________
