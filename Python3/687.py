__________________________________________________________________________________________________
sample 336 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def helper(self, node):
        cur_path=0
        if node.left:
            n, val = self.helper(node.left)
            if val==node.val:
                cur_path = n+1
                if self.longest_path<cur_path:
                    self.longest_path = cur_path
        if node.right:
            n, val = self.helper(node.right)
            if val==node.val:
                cur_path2 = n+1
                if self.longest_path<(cur_path+cur_path2):
                    self.longest_path = (cur_path+cur_path2)
                cur_path = max(cur_path, cur_path2)
        return cur_path, node.val
        
    def longestUnivaluePath(self, root: TreeNode) -> int:
        self.longest_path = 0
        if root:
            self.helper(root)
        return self.longest_path
__________________________________________________________________________________________________
sample 17088 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def longestUnivaluePath(self, root: TreeNode) -> int:
        longestPath = [float('-inf')]
        def longestCommonPath(root, val):
            if not root:
                return 0
            left = right = 0
            found = False
            if root.val == val:
                found = True
                left = longestCommonPath(root.left, val)
                right = longestCommonPath(root.right, val)
            else:
                left = longestCommonPath(root.left, root.val)
                right = longestCommonPath(root.right, root.val)
            if left+right+1 > longestPath[0]:
                longestPath[0] = left+right+1
            return max(left+1, right+1) if found else 0
        if not root:
            return 0
        longestCommonPath(root, root.val)
        return longestPath[0]-1
__________________________________________________________________________________________________
