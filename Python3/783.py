__________________________________________________________________________________________________
sample 24 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.prev = None
        self.small = float('inf')
        
    def minDiffInBST(self, root: TreeNode) -> int:
        self.inorderTraversal(root)
        return self.small
        
    def inorderTraversal(self, root: TreeNode) -> None:
        if not root:
            return None
        self.inorderTraversal(root.left)
        if self.prev:
            self.small = min(self.small, abs(root.val - self.prev.val))
        self.prev = root
        self.inorderTraversal(root.right)
__________________________________________________________________________________________________
sample 13012 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        self.res = sys.maxsize
        self.prev = -999999
        def minDiffInBSTUtil(root):
            if root == None:
                return 
            minDiffInBSTUtil(root.left)
            if (root.val - self.prev) <  self.res:
                self.res  = root.val - self.prev
            self.prev = root.val
            minDiffInBSTUtil(root.right)
            return
        minDiffInBSTUtil(root)
        return self.res
__________________________________________________________________________________________________
