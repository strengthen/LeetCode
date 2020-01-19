__________________________________________________________________________________________________
sample 64 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class FindElements:
    def __init__(self, root: TreeNode):
        self.root = root
        self.d = {}
        if self.root is not None:
            self.root.val = 0
            self.fillin(self.root)
            self.d[0] = True
            
    def fillin(self, root):
        if root is None or (root.left is None and root.right is None):
            return
        if root.left is not None and root.right is not None:
            root.left.val = root.val * 2 + 1
            root.right.val = root.val * 2 + 2
            self.d[root.left.val] = True
            self.d[root.right.val] = True
            self.fillin(root.left)
            self.fillin(root.right)
        elif root.left is not None:
            root.left.val = root.val * 2 + 1
            self.d[root.left.val] = True
            self.fillin(root.left)
        else:
            root.right.val = root.val * 2 + 2
            self.d[root.right.val] = True
            self.fillin(root.right)

    def find(self, target: int) -> bool:
        if not self.d:
            return False
        return target in self.d

# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
__________________________________________________________________________________________________
sample 68 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class FindElements:
    
    def recoverTree(self, root, val):
        
        if not root:
            return
        
        root.val = val
        self.values.add(val)
        if root.left:
            self.recoverTree(root.left, 2 * val + 1)
        if root.right:
            self.recoverTree(root.right, 2 * val + 2)

    def __init__(self, root: TreeNode):
        self.values = set()
        self.recoverTree(root, 0)
__________________________________________________________________________________________________
