__________________________________________________________________________________________________
sample 40 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        
        queue = collections.deque([root])
        level_largest = []
        while queue:
            level_len = len(queue)
            res = float("-inf")
            while level_len > 0:
                node = queue.popleft()
                if node.val > res:
                    res = node.val
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                level_len -= 1
            level_largest.append(res)
            
        return level_largest
__________________________________________________________________________________________________
sample 15608 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        if not root: return []
        maxes = []
        q = [root]
        while q:
            maxes.append(max(n.val for n in q))
            q = [c for n in q for c in (n.left, n.right) if c]
        return maxes
__________________________________________________________________________________________________
