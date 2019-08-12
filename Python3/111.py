__________________________________________________________________________________________________
sample 28 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        if not root.left:
            return 1 + self.minDepth(root.right)
        if not root.right:
            return 1 + self.minDepth(root.left)
        
        return 1 + min(self.minDepth(root.left), self.minDepth(root.right))
__________________________________________________________________________________________________
sample 14236 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0

        node_queue = []
        node_queue.append((root, 1))
        depth = 0
        min_depth = None

        while len(node_queue) > 0:
            (curr_node, dep_lvl) = node_queue.pop(0)
            
            if not curr_node.left and not curr_node.right:
                min_depth = dep_lvl if not min_depth or min_depth > dep_lvl else min_depth

            if curr_node.left:
                node_queue.append((curr_node.left, dep_lvl+1))

            if curr_node.right:
                node_queue.append((curr_node.right, dep_lvl+1))

        return min_depth
__________________________________________________________________________________________________
