__________________________________________________________________________________________________
sample 40 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def removeLeafNodes(self, root: TreeNode, target: int) -> TreeNode:
        if root.left:
            root.left = self.removeLeafNodes(root.left, target)
        if root.right:
            root.right = self.removeLeafNodes(root.right, target)
        # if node is leef, check the value is same as target or not
        if root.left is None and root.right is None:
            if root.val == target:
                return None
            else:
                return root
        return root
__________________________________________________________________________________________________
sample 52 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def removeLeafNodes(self, root: TreeNode, target: int) -> TreeNode:
        def postorder(node, parent, is_left=True):
            if node is not None:
                ld = postorder(node.left, node)
                rd = postorder(node.right, node, False)
                if ld and rd and node.val == target:
                    if parent is not None:
                        if is_left:
                            parent.left = None
                        else:
                            parent.right = None
                    return True
                return False
            else:
                return True
        d = postorder(root, None)
        return None if d else root
__________________________________________________________________________________________________
