__________________________________________________________________________________________________
sample 76 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTree(self, root: TreeNode, arr: List[TreeNode]):
        if root is None:
            return
        if(root.left):
            self.inorderTree(root.left, arr)
        arr.append(root)
        if(root.right):
            self.inorderTree(root.right, arr)
            
    def increasingBST(self, root: TreeNode) -> TreeNode:
        if root is None:
            return root
        arr = []
        self.inorderTree(root, arr)
        length = len(arr)
        root = arr[0]
        cur = root
        for i in range(1, length):
            cur.left = None
            cur.right = arr[i]
            cur = arr[i]
        cur.left = None
        cur.right = None
        return root
__________________________________________________________________________________________________
sample 13168 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def increasingBST(self, root):
        def inorder(node):
            if node:
                inorder(node.left)
                node.left = None
                self.cur.right = node
                self.cur = node
                inorder(node.right)

        ans = self.cur = TreeNode(None)
        inorder(root)
        return ans.right
__________________________________________________________________________________________________
