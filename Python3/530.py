__________________________________________________________________________________________________
sample 48 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        res = []
        self.dfs(root,res)
        result = []
        for i in range(1,len(res)):
            result.append(abs(res[i]-res[i-1]))
        return min(result)
        
    def dfs(self, root, res):
        if not root:
            return []
        else:
            if root.left:
                self.dfs(root.left, res)
            res.append(root.val)
            if root.right:
                self.dfs(root.right, res)
            return res
__________________________________________________________________________________________________
sample 15308 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getMinimumDifference(self, root):
        L = []
        def dfs(node):
            if node.left: dfs(node.left)
            L.append(node.val)
            if node.right: dfs(node.right)
        dfs(root)
        return min(abs(a - b) for a, b in zip(L, L[1:]))
__________________________________________________________________________________________________
