__________________________________________________________________________________________________
sample 40 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Found(Exception): pass

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        answer, counter = 0, 0

        def dfs(node):
            if node == None: return

            nonlocal counter, answer

            dfs(node.left)

            counter += 1
            if counter == k:
                answer = node.val
                raise Found

            dfs(node.right)
        
        try:
            dfs(root)
        except Found:
            pass
        
        return answer
__________________________________________________________________________________________________
sample 15392 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        stack = []
        while root:
            stack.append(root)
            root = root.left
            
        count = 1
        while stack and count <= k:
            cur = stack.pop()
            count = count + 1
            while cur.right:
                stack.append(cur.right)
                cur.right = cur.right.left
        return cur.val
__________________________________________________________________________________________________
