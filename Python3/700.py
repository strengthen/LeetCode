__________________________________________________________________________________________________
sample 68 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if val == root.val:
            return root
        
        if val < root.val:
            if root.left:
                return self.searchBST(root.left, val)
            return None
        
        if root.right:
            return self.searchBST(root.right, val)
        
        return None
__________________________________________________________________________________________________
sample 15128 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:
            return []

        trav = root
        while trav:
            if trav.val == val:
                return trav
            elif trav.val < val:
                trav = trav.right
            else:
                trav = trav.left
__________________________________________________________________________________________________
