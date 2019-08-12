__________________________________________________________________________________________________
sample 24 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        return root is None or self.isMirror(root.left,root.right)
    def isMirror(self,l,r):
        if l is None and r is None:
            return True
        elif l is None or r is None:
            return None
        else:
            return l.val==r.val and self.isMirror(l.left,r.right) and self.isMirror(l.right,r.left)
__________________________________________________________________________________________________
sample 12960 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isMirror(self, node1,node2):
        if(not node1 and not node2):
            return True
        if(not node1 or not node2):
            return False
        # if(node1.val != node2.val):
        #     return False
        return (node1.val == node2.val) and self.isMirror(node1.left,node2.right) and self.isMirror(node1.right,node2.left)
        
    def isSymmetric(self, root: TreeNode) -> bool:
        return self.isMirror(root, root)
        # print(root)
__________________________________________________________________________________________________
