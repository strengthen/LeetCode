__________________________________________________________________________________________________
sample 68 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        # if not t1 and not t2:
        #     return
        if not t1 or not t2:
            return t1 or t2
        t1.val += t2.val
        t1.left = self.mergeTrees(t1.left, t2.left)
        t1.right = self.mergeTrees(t1.right, t2.right)
        return t1
__________________________________________________________________________________________________
sample 13300 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        
        if not t1 and not t2:
            return None
        
        if not t1 and  t2:
            return t2
        
        if  t1 and not t2:
            return t1
        
            
        queue1 = [t1]
        queue2 = [t2]
        
        
        
        while queue1:
            len0 = len(queue1)
            for i in range(len0):
                tem1 = queue1.pop(0)
                tem2 = queue2.pop(0)
                tem1.val += tem2.val
                
                if tem1.left and tem2.left:
                    queue1.append(tem1.left)
                    queue2.append(tem2.left)
                
                if tem1.right and tem2.right:
                    queue1.append(tem1.right)
                    queue2.append(tem2.right)
                
                if not tem1.left and tem2.left:
                    tem1.left = tem2.left
                
                if not tem1.right and tem2.right:
                    tem1.right = tem2.right
        return t1
__________________________________________________________________________________________________
