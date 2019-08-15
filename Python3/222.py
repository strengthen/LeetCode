__________________________________________________________________________________________________
sample 68 ms submission
# # Definition for a binary tree node.
# # class TreeNode:
# #     def __init__(self, x):
# #         self.val = x
# #         self.left = None
# #         self.right = None

# class Solution:
#     def countNodes(self, root):
#         if not root:
#             return 0
#         h1, h2 = self.height(root.left), self.height(root.right)
#         print(h1,h2)
#         if h1 > h2: # right child is full 
#             return self.countNodes(root.left) +  2 ** h2 
#         else: # left child is full 
#             return 2 ** h1 + self.countNodes(root.right)

#     # the height of the left-most leaf node
#     # def height1(self, root):
#     #     h = 0
#     #     while root:
#     #         h += 1
#     #         root = root.left
#     #     return h

#     def height(self, root):
#         if not root:
#             return 0
#         return self.height(root.left) + 1
class Solution:
    def compute_depth(self, node: TreeNode) -> int:
        """
        Return tree depth in O(d) time.
        """
        d = 0
        while node.left:
            node = node.left
            d += 1
        return d

    def exists(self, idx: int, d: int, node: TreeNode) -> bool:
        """
        Last level nodes are enumerated from 0 to 2**d - 1 (left -> right).
        Return True if last level node idx exists. 
        Binary search with O(d) complexity.
        """
        left, right = 0, 2**d - 1
        for _ in range(d):
            pivot = left + (right - left) // 2
            if idx <= pivot:
                node = node.left
                right = pivot
            else:
                node = node.right
                left = pivot + 1
        return node is not None
        
    def countNodes(self, root: TreeNode) -> int:
        # if the tree is empty
        if not root:
            return 0
        
        d = self.compute_depth(root)
        # if the tree contains 1 node
        if d == 0:
            return 1
        
        # Last level nodes are enumerated from 0 to 2**d - 1 (left -> right).
        # Perform binary search to check how many nodes exist.
        left, right = 1, 2**d - 1
        while left <= right:
            pivot = left + (right - left) // 2
            if self.exists(pivot, d, root):
                left = pivot + 1
            else:
                right = pivot - 1
        
        # The tree contains 2**d - 1 nodes on the first (d - 1) levels
        # and left nodes on the last level.
        return (2**d - 1) + left
__________________________________________________________________________________________________
sample 20788 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def countNodes(self, root: TreeNode) -> int:
        def count(root):
            if not root: return 0
            left = count(root.left)
            right = count(root.right)
            return 1+left+right
        return count(root)
__________________________________________________________________________________________________
