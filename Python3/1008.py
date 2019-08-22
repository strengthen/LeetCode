__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def bstFromPreorder(self, pre) -> TreeNode:
        if not pre:
            return None
        root = TreeNode(pre[0])
        for i in range(1,len(pre)):
            node = root
            while node:
                prev = node
                side = (pre[i] > node.val)
                node = (node.left, node.right)[side]
            node = TreeNode(pre[i])
            prev.left, prev.right = (node, prev.left)[side], (prev.right, node)[side]
        return root
__________________________________________________________________________________________________
sample 12864 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        if not preorder: return None
        root = TreeNode(preorder[0])
        root.left = self.bstFromPreorder([val for val in preorder if val < preorder[0]])
        root.right = self.bstFromPreorder([val for val in preorder if val > preorder[0]])
        return root        
__________________________________________________________________________________________________
