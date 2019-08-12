__________________________________________________________________________________________________
sample 52 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        index_map = {v:k for k,v in enumerate(inorder)}
        R_postorder = postorder[::-1]
        postorder_index = 0 
        def dfs(left,right):
            if left == right:
                return None
            nonlocal postorder_index
            val = R_postorder[postorder_index]
            postorder_index += 1
            root = TreeNode(val)
            mid = index_map[val]
            root.right = dfs(mid+1,right)
            root.left = dfs(left,mid)
            return root
        return dfs(0,len(postorder))
__________________________________________________________________________________________________
sample 18116 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        inorder_map = {}
        for i, n in enumerate(inorder):
            inorder_map[n] = i
        
        def build(lo: int, hi: int) -> TreeNode:
            if lo > hi:
                return None
            val = postorder.pop()
            root = TreeNode(val)
            pos = inorder_map[val]
            root.right = build(pos + 1, hi)
            root.left = build(lo, pos - 1)
            return root
        
        return build(0, len(inorder) - 1)
__________________________________________________________________________________________________
