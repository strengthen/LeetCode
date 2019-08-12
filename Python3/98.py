__________________________________________________________________________________________________
sample 36 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if not root:
            return True
        
        def checkBST(node, left, right):
            if node.val >= right or node.val <= left:
                return False
            if node.left:
                if not checkBST(node.left, left, node.val):
                    return False
            if node.right:
                if not checkBST(node.right, node.val, right):
                    return False
            return True
        
        return checkBST(root, -float('inf'), float('inf'))
__________________________________________________________________________________________________
sample 15472 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        pre, cur, stack = None, root, []
        while stack or cur:
            while cur:
                stack.append(cur)
                cur = cur.left
            s = stack.pop()
            if pre and s.val <= pre.val:
                return False
            pre, cur = s, s.right
        return True
__________________________________________________________________________________________________
