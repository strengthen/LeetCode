__________________________________________________________________________________________________
sample 16 ms submission
# class Solution: #栈的精髓：把 递归中最后处理 的 压在最前面 
#     def postorderTraversal(self, root: TreeNode) -> List[int]:
#         res = []   
#         def recursion(root):
#             if not root: 
#                 return
#             recursion(root.left)
#             recursion(root.right)
#             res.append(root.val)
            
#         recursion(root)
#         return res
            
class Solution: #栈的精髓：把 递归中最后处理 的 压在最前面 
    def postorderTraversal(self, root: TreeNode) -> List[int]:  
        if not root: return []
        
        res = []
        stack = [(root, False)]
        while stack:
            node, visited = stack.pop()
            if visited:
                res.append(node.val)
            else:
                stack.append((node, True))
                if node.right:
                    stack.append((node.right, False))
                if node.left:
                    stack.append((node.left, False))
                
        return res
__________________________________________________________________________________________________
sample 12988 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        self.dfs(root, ans)
        return ans
    
    def dfs(self, root, ans):
        if root is None:
            return
        
        
        self.dfs(root.left, ans)
        self.dfs(root.right, ans)
        ans.append(root.val)
__________________________________________________________________________________________________
