__________________________________________________________________________________________________
sample 64 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        values = set()
        return self.find(root, k, values)
        
    def find(self, node, k, values):
        if node is None:
            return False
        if k - node.val in values:
            return True
        
        values.add(node.val)
        return self.find(node.left, k, values) or self.find(node.right, k, values)
__________________________________________________________________________________________________
sample 15348 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        if not root:
            return False        
        queue, s = [root], set()
        for i in queue:
            if k - i.val in s:
                return True
            s.add(i.val)
            if i.left:
                queue.append(i.left)
            if i.right:
                queue.append(i.right)
                
        return False        
__________________________________________________________________________________________________
