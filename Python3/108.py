__________________________________________________________________________________________________
sample 64 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, A: List[int]) -> TreeNode:
        
        
        def helper(start, end):
            if start < end:
                mid = start + (end-start) // 2
                node = TreeNode(A[mid])
                node.left = helper(start, mid)
                node.right = helper(mid+1, end)
                return node
        
        return helper(0, len(A))
__________________________________________________________________________________________________
sample 15396 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        
        def buildTree(left, right):
            if left > right:
                return None
            
            mid = (left + right) // 2
            node = TreeNode(nums[mid])
            
            node.left = buildTree(left, mid - 1)
            node.right = buildTree(mid + 1, right)
            
            return node
        
    
        return buildTree(0, len(nums) - 1)
__________________________________________________________________________________________________
