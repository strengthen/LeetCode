__________________________________________________________________________________________________
sample 24 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        
        self.res = []
        
        
        def dfs(root,current):
            if not root:
                return
            
            if not root.left and not root.right:
                self.res.append(current+str(root.val))
            
            
            if root.left:
                dfs(root.left,current + str(root.val) + '->')
            
            if root.right:
                dfs(root.right,current+ str(root.val) + '->')
        
        dfs(root,'')
        return self.res
__________________________________________________________________________________________________
sample 12960 kb submission
#
# @lc app=leetcode id=257 lang=python3
#
# [257] Binary Tree Paths
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.record = []

    def binaryTreePaths(self, root: TreeNode, currentString: str = "") -> List[str]:
        if not root:
            return []

        if not root.left and not root.right:
            currentString += str(root.val)
            self.record.append(currentString)
        else:
            if root.left: self.binaryTreePaths(root.left, currentString + str(root.val) + "->")
            if root.right: self.binaryTreePaths(root.right, currentString + str(root.val) + "->")

        return self.record
__________________________________________________________________________________________________
