__________________________________________________________________________________________________
sample 308 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        result = []
        self.processTree(root1, result)
        self.processTree(root2, result)
        result.sort()
                
        return result
            
    def processTree(self, root: TreeNode, nums: List[int]) -> None:
        if root and root.left:
            self.processTree(root.left, nums)
        if root:
            nums.append(root.val)
        if root and root.right:
            self.processTree(root.right, nums)
__________________________________________________________________________________________________
sample 312 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]: 
        def inorder(root, ans):
            if root.left:
                inorder(root.left, ans)
            ans.append(root.val)
            if root.right:
                inorder(root.right, ans)
                
        seq1 = []
        seq2 = []
        if root1:
            inorder(root1, seq1)
        if root2:
            inorder(root2, seq2)
        ans = seq1+seq2
        ans.sort()
        return ans
__________________________________________________________________________________________________
