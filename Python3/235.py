__________________________________________________________________________________________________
sample 68 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.ans = None 
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
  
        p_val = p.val
        q_val = q.val
        node = root
        while node:
            parent_val = node.val
            if p_val>parent_val and q_val>parent_val:
                node = node.right
            elif p_val<parent_val and q_val<parent_val:
                node = node.left
            else:
                return node                 
__________________________________________________________________________________________________
sample 17244 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        parent_val = root.val
        p_val = p.val
        q_val = q.val
        
        if p_val > parent_val and q_val > parent_val:
            return self.lowestCommonAncestor(root.right, p, q)
        elif p_val < parent_val and q_val < parent_val:
            return self.lowestCommonAncestor(root.left, p, q)
        else:
            return root
__________________________________________________________________________________________________
