__________________________________________________________________________________________________
sample 44 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def trimBST(self, root: TreeNode, L: int, R: int) -> TreeNode:
        if not root:
            return root
        return self.helper(root, L, R)
    
    def helper(self, node: TreeNode, L, R) -> TreeNode:
        if not node:
            return None
        elif node.val > R:
            return self.helper(node.left, L, R)
        elif node.val < L:
            return self.helper(node.right, L, R)
        else:
            node.left = self.helper(node.left, L, R)
            node.right = self.helper(node.right, L, R)
            return node
__________________________________________________________________________________________________
sample 17152 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def trimBST(self, root: TreeNode, L: int, R: int) -> TreeNode:
        def trim(node):
            if not node:
                return None
            elif node.val > R:
                return trim(node.left)
            elif node.val < L:
                return trim(node.right)
            else:
                node.left = trim(node.left)
                node.right = trim(node.right)
                return node

        return trim(root)
__________________________________________________________________________________________________
