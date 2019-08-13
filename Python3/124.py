__________________________________________________________________________________________________
sample 76 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        MAX = {}
        def recurse(root, MAX):
            if not root: return 0
            
            left = recurse(root.left, MAX)
            right = recurse(root.right, MAX)
            
            if left < 0: left = 0
            if right < 0: right = 0
            if left+right+root.val > MAX['max']: 
                MAX['max'] = left+right+root.val
                
            return root.val + max(left, right)
            
        MAX['max'] = float('-inf')
        recurse(root, MAX)
        return MAX['max']
__________________________________________________________________________________________________
sample 20504 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.maxvalue = -99999999999
        
    def processNode(self, node):
        if not node:
            return 0
        l = self.processNode(node.left)
        r = self.processNode(node.right)
        newvalue = max( node.val, 
                            l + node.val,
                            r + node.val)
        #print("{},{},{}".format(node.val, newvalue, self.maxvalue))
        self.maxvalue = max(newvalue, self.maxvalue, l + r + node.val)
        return newvalue
        
    def maxPathSum(self, root: TreeNode) -> int:
        self.processNode(root)
        return self.maxvalue        
__________________________________________________________________________________________________
