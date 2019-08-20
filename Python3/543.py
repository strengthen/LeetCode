__________________________________________________________________________________________________
sample 36 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.ans = 0
        
        def depth(p):
            if not p: return 0
            left, right = depth(p.left), depth(p.right)
            self.ans = max(self.ans, left+right)
            return 1 + max(left, right)
            
        depth(root)
        return self.ans
__________________________________________________________________________________________________
sample 15344 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recursion(self, node):
        if node == None: return 0
        else:
            dl = self.recursion(node.left)
            dr = self.recursion(node.right)
            self.max = max(dl+dr+1, self.max)
            return max(dl,dr) + 1
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if root == None: return 0
        self.max = 0
        self.recursion(root)
        return self.max-1        
__________________________________________________________________________________________________
