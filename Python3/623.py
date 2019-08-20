__________________________________________________________________________________________________
sample 44 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        if d == 1:
            new = TreeNode(v)
            new.left = root
            return new
        
        level = 1
        frontier = [root]
        while level < d-1 and frontier:
            tmp = []
            level += 1
            for x in frontier:
                if x.left: tmp.append(x.left)
                if x.right: tmp.append(x.right)
            frontier = tmp
        
        for x in frontier:
            l = x.left
            r = x.right
            x.left = TreeNode(v)
            x.left.left = l
            x.right = TreeNode(v)
            x.right.right = r
        
        return root
__________________________________________________________________________________________________
sample 14256 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        dummy, dummy.left = TreeNode(None), root
        row = [dummy]
        for _ in range(d - 1):
            row = [kid for node in row for kid in (node.left, node.right) if kid]
        for node in row:
            node.left, node.left.left = TreeNode(v), node.left
            node.right, node.right.right = TreeNode(v), node.right
        return dummy.left
__________________________________________________________________________________________________
