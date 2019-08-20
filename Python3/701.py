__________________________________________________________________________________________________
sample 104 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:
            return
        
        if val > root.val:
            if root.right == None:
                root.right = TreeNode(val)
            else:
                self.insertIntoBST(root.right, val)
        elif val < root.val:
            if root.left == None:
                root.left = TreeNode(val)
            else:
                self.insertIntoBST(root.left, val)
        
        return root
__________________________________________________________________________________________________
sample 15252 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def insertIntoBST(self, root, val):
        if(root == None): return TreeNode(val);
        if(root.val < val): root.right = self.insertIntoBST(root.right, val);
        else: root.left = self.insertIntoBST(root.left, val);
        return(root)
__________________________________________________________________________________________________
