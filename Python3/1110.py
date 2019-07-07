__________________________________________________________________________________________________
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self, root: TreeNode, detached: bool):
        if not root:
            return
        if detached and root.val not in self.x:
            self.ans.append(root)
        detached = (root.val in self.x)
        self.dfs(root.left, detached)
        self.dfs(root.right, detached)
        if root.left and root.left.val in self.x:
            root.left = None
        if root.right and root.right.val in self.x:
            root.right = None
        if root.val in self.x:
            del root
        
    
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        self.x = set(to_delete)
        self.ans = []
        self.dfs(root, detached=True)
        return self.ans
__________________________________________________________________________________________________

__________________________________________________________________________________________________
