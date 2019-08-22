__________________________________________________________________________________________________
sample 20 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.recBstToGst(root, 0)
        return root
        
    def recBstToGst(self, root: TreeNode, preVal: int) -> int:
        if root is None:
            return preVal
        
        res = self.recBstToGst(root.right, preVal)
        root.val += res
        return self.recBstToGst(root.left, root.val)
__________________________________________________________________________________________________
sample 24 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        def recur(node, sumTillNow):
            if not node:
                return sumTillNow
            node.val += recur(node.right, sumTillNow)
            return recur(node.left, node.val)
            
        recur(root, 0)
        return root
__________________________________________________________________________________________________
