__________________________________________________________________________________________________
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        self.memo = {None : 0}
        self.depth(root)
        def helper(node):
            if node is None:
                return None
            else:
                l, r = self.memo[node.left], self.memo[node.right]
                if l == r:
                    return node
                elif l > r:
                    return helper(node.left)
                else:
                    return helper(node.right)
        return helper(root)
    
    def depth(self, node):
        if node is not None:
            l, r = self.depth(node.left), self.depth(node.right)
            d = max(l, r) + 1
            self.memo[node] = d
            return d
        else:
            return 0

__________________________________________________________________________________________________

__________________________________________________________________________________________________
