__________________________________________________________________________________________________
sample 28 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def returnDepth(self, root):
        if root == None:
            return (0, None)
        (leftDepth, leftNode) = self.returnDepth(root.left)
        rightDepth, rightNode = self.returnDepth(root.right)
        if leftDepth == rightDepth:
            return (leftDepth+1, root)
        elif rightDepth > leftDepth:
            return (rightDepth+1, rightNode)
        else:
            return (leftDepth+1, leftNode)
    
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        depth, node = self.returnDepth(root)
        return node        
__________________________________________________________________________________________________
sample 13132 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        def deep(root):
            if not root: 
                return 0, None
            l, r = deep(root.left), deep(root.right)
            if l[0] > r[0]: 
                return l[0] + 1, l[1]
            elif l[0] < r[0]: 
                return r[0] + 1, r[1]
            else: 
                return l[0] + 1, root
        return deep(root)[1]
__________________________________________________________________________________________________
