__________________________________________________________________________________________________
sample 28 ms submission
#
# @lc app=leetcode id=979 lang=python3
#
# [979] Distribute Coins in Binary Tree
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
  def distributeCoins(self, root: TreeNode) -> int:
    self.res = 0

    def dfs(node):
      if not node:
        return

      if node.left:
        dfs(node.left)
        node.val += node.left.val - 1
      if node.right:
        dfs(node.right)
        node.val += node.right.val - 1
      
      self.res += abs(node.val - 1)
    
    dfs(root)
    return self.res
__________________________________________________________________________________________________
sample 12952 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.count = 0
    
    def distributeCoins(self, root: TreeNode) -> int:
        self.helper(root)
        return self.count
    
    def helper(self, root):
        if not root:
            return 0
        
        childRequire = self.helper(root.left) + self.helper(root.right)
        if root.val == childRequire + 1:
            return 0
        elif root.val < childRequire+1:
            thisRequire = childRequire+1 - root.val
            self.count += thisRequire
            return thisRequire
        elif root.val > childRequire+1:
            thisGive = root.val - (childRequire+1)
            self.count += thisGive
            return -thisGive
__________________________________________________________________________________________________
