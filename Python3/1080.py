__________________________________________________________________________________________________
sample 76 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sufficientSubset(self, root: TreeNode, limit: int) -> TreeNode:
        if not root:
            return None
        #print(root.val, limit)
        if root.left == root.right == None:
            return root if root.val >= limit else None
        root.left = self.sufficientSubset(root.left, limit - root.val)
        root.right = self.sufficientSubset(root.right, limit - root.val)
        return root if (root.left or root.right) else None
__________________________________________________________________________________________________
sample 80 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sufficientSubset(self, root: TreeNode, limit: int) -> TreeNode:
        def DFS(node, s):
            s += node.val
            if not node.left and not node.right:
                if s >= limit:
                    return node
                else: return None
            # left, right = None, None
            if node.left and not DFS(node.left, s):
                node.left = None
            if node.right and not DFS(node.right, s):
                node.right = None
                
            if not node.left and not node.right:
                return None
            else:
                return node        
        
        if not root: return
        
        return DFS(root, 0)
__________________________________________________________________________________________________
sample 84 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sufficientSubset(self, root: TreeNode, limit: int) -> TreeNode:
        if not root:
            return root
        if not root.left and not root.right:
            return root if root.val >= limit else None
        
        root.left = self.sufficientSubset(root.left, limit - root.val)
        root.right = self.sufficientSubset(root.right, limit - root.val)
        return root if root.left or root.right else None