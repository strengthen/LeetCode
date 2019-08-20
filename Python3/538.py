__________________________________________________________________________________________________
sample 60 ms submission
class Solution(object):
    def convertBST(self, root):
        total = 0
        
        node = root
        stack = []
        while stack or node is not None:
            # push all nodes up to (and including) this subtree's maximum on
            # the stack.
            while node is not None:
                stack.append(node)
                node = node.right

            node = stack.pop()
            total += node.val
            node.val = total

            # all nodes with values between the current and its parent lie in
            # the left subtree.
            node = node.left

        return root
__________________________________________________________________________________________________
sample 15472 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        if not root:
            return root
        def convertToGreater(node, plus):
            if not node.right:
                node.val += plus
            else:
                node.val += convertToGreater(node.right, plus)
            if not node.left:
                return node.val
            else:
                return convertToGreater(node.left, node.val)
        
        convertToGreater(root, 0)
        return root
__________________________________________________________________________________________________
