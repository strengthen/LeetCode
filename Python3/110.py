__________________________________________________________________________________________________
sample 40 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:      
        def isBalanced_root(node):
            if not node:
                return -1
            left = isBalanced_root(node.left)
            if left != -2:
                right = isBalanced_root(node.right)
            if left == -2 or right == -2 or abs(left-right) > 1:
                return -2
            return 1 + max(left, right)
        return isBalanced_root(root) != -2
__________________________________________________________________________________________________
sample 17720 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def caldepth(self,root):
        if root is None:
            return 0
       
        
        left = self.caldepth(root.left)
        
        
        right = self.caldepth(root.right)
        
        if abs(left-right)>1:
            self.flag = True
            
      
        return max(left, right)+1
    
    
    def dohelp(self,root):
        leftdepth = self.caldepth(root.left)
        rightdepth = self.caldepth(root.right)
        if abs(leftdepth-rightdepth)>1:
            return False
        else:
            return True
       
    def isBalanced(self, root: TreeNode) -> bool:
        
        if root is None:
            return True
        self.flag = False
        
        if self.dohelp(root) is False:
            return False
        
        ret = self.isBalanced(root.left)
        
        if ret is False:
            return False
        
        ret = self.isBalanced(root.right)
        
        if ret is False:
            return False
        
       
        return True 
__________________________________________________________________________________________________
