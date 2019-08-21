__________________________________________________________________________________________________
sample 24 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        def f(tree):
            if tree:
                if tree.left: tree.left = f(tree.left)
                if tree.right: tree.right = f(tree.right)
                if tree.val != 0 or tree.left or tree.right:
                    return tree
        return f(root)
__________________________________________________________________________________________________
sample 13056 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        if root is None:
            return None

        if root.val == 0 and root.left is None and root.right is None:
            return None
        
        root.left = self.pruneTree(root.left)
        root.right = self.pruneTree(root.right)
        
        if root.val == 0 and root.left is None and root.right is None:
            return None
        
        return root
__________________________________________________________________________________________________
